//
// Created by wciq1208 on 19-10-29.
//

#include "list.h"
#include <memory>
#include <iostream>


template <class T>
std::shared_ptr<T> instance() {
    return std::make_shared<T>();
}

#include <vector>
int main() {
    auto components = ComponentsFactory<int, float, double >::creator();
    *(components.get<double>().get()) = 0.7;
    std::cout << *(components.get<double>().get()) << std::endl;
    std::cout << components.find<char>() << std::endl;
}