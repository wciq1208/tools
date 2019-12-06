//
// Created by wciq1208 on 19-12-6.
//

#ifndef TOOLS_CONTAINER_COMPONENTS_H_
#define TOOLS_CONTAINER_COMPONENTS_H_

#include "list.h"
#include <memory>

template <class... Args>
class Components {
private:
    using type_list = typename type::Create<Args...>::type;
    using data_type = std::tuple<std::shared_ptr<Args>...>;
    data_type data_;
public:
    explicit Components(data_type &&data): data_(std::move(data)) {};
    template <class T>
    std::shared_ptr<T> &get() {
        return std::get<type::Find<type_list, T>::value>(data_);
    }
    template <class T>
    size_t find() {
        return type::Find<type_list, T>::value;
    }
};

template <class T>
std::shared_ptr<T> instance();


template <class ...Args>
class ComponentsFactory {
public:
    typedef Components<Args...> type;
    static type creator() {
        return type(std::make_tuple(instance<Args>()...));
    }
};

#endif //TOOLS_CONTAINER_COMPONENTS_H_
