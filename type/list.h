//
// Created by wciq1208 on 19-12-6.
//

#ifndef TOOLS_TYPE_LIST_H_
#define TOOLS_TYPE_LIST_H_

#include <cstddef>
#include "meta.h"

namespace type {
namespace list {

template<class V, class N = Empty>
struct List {
    typedef V value;
    typedef N next;
};

template<class... Args>
struct Creator;

template<class V, class... Args>
struct Creator<V, Args...> {
    typedef List<V, typename Creator<Args...>::type> type;
};

template<class V>
struct Creator<V> {
    typedef List<V, Empty> type;
};

template<>
struct Creator<> {
    typedef List<Empty, Empty> type;
};

template<class T, size_t i>
struct IndexOf;

template<class V, class N>
struct IndexOf<List<V, N>, 0> {
    typedef V type;
};

template<class V>
struct IndexOf<List<V, Empty>, 1> {
    typedef Empty type;
};

template<class V, class N, size_t i>
struct IndexOf<List<V, N>, i> {
    typedef typename IndexOf<N, i - 1>::type type;
};

namespace impl {
template<class TList, class T, size_t i>
struct Find;

template<class V, class T, size_t i>
struct Find<List<V, Empty>, T, i> {
    static const size_t value = -1;
};

template<class T, size_t i>
struct Find<List<T, Empty>, T, i> {
    static const size_t value = i;
};

template<class N, class T, size_t i>
struct Find<List<T, N>, T, i> {
    static const size_t value = i;
};

template<class V, class N, class T, size_t i>
struct Find<List<V, N>, T, i> {
    static const size_t value = Find<N, T, i + 1>::value;
};
} // namespace impl

template<class TList, class T>
struct Find {
    static const size_t value = impl::Find<TList, T, 0>::value;
};

template<class TList, class T1, class T2>
struct ReplaceByType;

template<class T1, class T2>
struct ReplaceByType<Empty, T1, T2> {
    typedef Empty type;
};

template<class V, class N, class T2>
struct ReplaceByType<List<V, N>, V, T2> {
    typedef List<T2, typename ReplaceByType<N, V, T2>::type> type;
};

template<class V, class N, class T1, class T2>
struct ReplaceByType<List<V, N>, T1, T2> {
    typedef List<V, typename ReplaceByType<N, T1, T2>::type> type;
};

template<class TList, size_t idx, class T2>
struct ReplaceByIndex;

template<size_t idx, class T2>
struct ReplaceByIndex<Empty, idx, T2> {
    typedef Empty type;
};

template<class V, class N, class T2>
struct ReplaceByIndex<List<V, N>, 0, T2> {
    typedef List<T2, N> type;
};

template<class V, class N, size_t idx, class T2>
struct ReplaceByIndex<List<V, N>, idx, T2> {
    typedef List<V, typename ReplaceByIndex<N, idx - 1, T2>::type> type;
};

namespace impl {
template<class TList, size_t len>
struct Length;

template<size_t len>
struct Length<Empty, len> {
    static const size_t value = len;
};

template<class V, class N, size_t len>
struct Length<List<V, N>, len> {
    static const size_t value = Length<N, len + 1>::value;
};
}

template<class TList>
struct Length {
    static const size_t value = impl::Length<TList, 0>::value;
};

template<class TList, class T>
struct RemoveByType;

template<class T>
struct RemoveByType<Empty, T> {
    typedef Empty type;
};

template<class V, class N>
struct RemoveByType<List<V, N>, V> {
    typedef typename RemoveByType<N, V>::type type;
};

template<class TList, class N, class T>
struct RemoveByType<List<TList, N>, T> {
    typedef List<TList, typename RemoveByType<N, T>::type> type;
};

template<class TList, size_t idx>
struct RemoveByIndex;

template<size_t idx>
struct RemoveByIndex<Empty, idx> {
    typedef Empty type;
};

template<class V, class N>
struct RemoveByIndex<List<V, N>, 0> {
    typedef N type;
};

template<class TList, class N, size_t idx>
struct RemoveByIndex<List<TList, N>, idx> {
    typedef List<TList, typename RemoveByIndex<N, idx - 1>::type> type;
};

namespace impl {
template<class TList1, class TList2>
struct Join;

template<class V, class TList2>
struct Join <List<V, Empty>, TList2> {
    typedef List<V, TList2> type;
};

template<class V, class N, class TList2>
struct Join <List<V, N>, TList2> {
    typedef List<V, typename Join<N, TList2>::type> type;
};
}

template<class TList1, class TList2>
struct Join {
    typedef typename impl::Join<TList1, TList2>::type type;
};

template <class TList, size_t idx, class T>
struct Insert;

template <class V, class T>
struct Insert <List<V, Empty>, 0, T> {
    typedef List<T, List<V>> type;
};

template <size_t idx, class T>
struct Insert <Empty, idx, T> {
    typedef List<T, Empty> type;
};

template <class V, class N, class T>
struct Insert <List<V, N>, 0, T> {
    typedef List<T, List<V, N>> type;
};

template <class V, class N, size_t idx, class T>
struct Insert <List<V, N>, idx, T> {
    typedef List<V, typename Insert<N, idx - 1, T>::type> type;
};
}
}

#endif //TOOLS_TYPE_LIST_H_
