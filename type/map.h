//
// Created by wciq1208 on 19-12-6.
//

#ifndef TOOLS_TYPE_MAP_H_
#define TOOLS_TYPE_MAP_H_

#include "list.h"
#include "pair.h"

namespace type {
namespace map {

template <class K, class V, class ...Args>
using Map = list::List<Pair<K, V>, Args...>;

template <class TMap, class K>
struct Get;

template <class K>
struct Get <Empty, K> {
    typedef Empty type;
};

template <class Key, class Value, class N>
struct Get <list::List<Pair<Key, Value>, N>, Key> {
    typedef Value type;
};

template <class Key, class Value, class N, class K>
struct Get <list::List<Pair<Key, Value>, N>, K> {
    typedef typename Get<N, K>::type type;
};

template <class TMap, class K, class V>
struct Set;

template <class K, class V>
struct Set <Empty, K, V> {
    typedef typename list::List<Pair<K, V>, Empty> type;
};

template <class Key, class Value, class N, class V>
struct Set <list::List<Pair<Key, Value>, N>, Key, V> {
    typedef typename list::List<Pair<Key, V>, typename Set<N, Key, V>::type> type;
};

template <class Key, class Value, class N, class K, class V>
struct Set <list::List<Pair<Key, Value>, N>, K, V> {
    typedef typename list::List<Pair<Key, Value>, typename Set<N, K, V>::type> type;
};

template <class TMap, class K>
struct Remove;

template <class K>
struct Remove <Empty, K> {
    typedef Empty type;
};

template <class Key, class Value, class N>
struct Remove <list::List<Pair<Key, Value>, N>, Key> {
    typedef typename Remove <N, Key>::type type;
};

template <class Key, class Value, class N, class K>
struct Remove <list::List<Pair<Key, Value>, N>, K> {
    typedef list::List<Pair<Key, Value>, typename Remove<N, K>::type> type;
};

template <class TMap>
struct NoDuplicate;

template <>
struct NoDuplicate <Empty> {
    typedef Empty type;
};

template <class Key, class Value, class N>
struct NoDuplicate <list::List<Pair<Key, Value>, N>> {
    typedef list::List<Pair<Key, Value>, typename NoDuplicate<typename Remove<N, Key>::type>::type> type;
};


template <class ...Items>
struct Creator;

template <class K, class V>
struct Creator<Pair<K, V>> {
    typedef Map<K, V, Empty> type;
};

template <class K, class V, class ...Items>
struct Creator<Pair<K, V>, Items...> {
    typedef typename NoDuplicate<Map<K, V, typename Creator<Items...>::type>>::type type;
};
}
}

#endif //TOOLS_TYPE_MAP_H_
