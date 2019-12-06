//
// Created by wciq1208 on 19-10-29.
//

#include "list.h"
#include <iostream>

using namespace type;

void replace_by_type() {
    using list = Create<int, float, double, int, float >::type;
    std::cout << std::is_same<ReplaceByType<list, int , char>::type, Create<char, float, double, char, float >::type>::value << std::endl;
    std::cout << std::is_same<ReplaceByType<list, char , int>::type, list>::value << std::endl;
    std::cout << std::is_same<ReplaceByType<list, float , int>::type, Create<int, int, double, int, int >::type>::value << std::endl;
}

void replace_by_index() {
    using list = Create<int, float, double, int, float >::type;
    std::cout << std::is_same<ReplaceByIndex<list, 0, char >::type, Create<char, float, double, int, float >::type>::value << std::endl;
    std::cout << std::is_same<ReplaceByIndex<list, 0, int >::type, list>::value << std::endl;
    std::cout << std::is_same<ReplaceByIndex<list, 1, char >::type, Create<int, char, double, int, float >::type>::value << std::endl;
    std::cout << std::is_same<ReplaceByIndex<list, 4, char >::type, Create<int, float, double, int, char >::type>::value << std::endl;
    std::cout << std::is_same<ReplaceByIndex<list, 10, char >::type, list>::value << std::endl;
}

void index_of() {
    using list = Create<int, float, double, int, float >::type;
    std::cout << std::is_same<IndexOf<list, 1>::type, float>::value << std::endl;
    std::cout << std::is_same<IndexOf<list, 0>::type, int>::value << std::endl;
    std::cout << std::is_same<IndexOf<list, 4>::type, float>::value << std::endl;
}

void find() {
    using list = Create<int, float, double, int, char >::type;
    std::cout << (Find<list, float>::value == 1) << std::endl;
    std::cout << (Find<list, int>::value == 0) << std::endl;
    std::cout << (Find<list, char>::value == 4) << std::endl;
    std::cout << (Find<list, bool >::value == -1) << std::endl;
}

void length() {
    using list1 = Create<int, float, double, int, char >::type;
    using list2 = Create<int>::type;
    std::cout << (Length<list1>::value == 5) << std::endl;
    std::cout << (Length<list2>::value == 1) << std::endl;
}

void remove_by_type() {
    using list1 = Create<int, float, double, int, char >::type;
    using list2 = Create<int, float, double, int, float >::type;
    using list3 = Create<int, float, double, int, float >::type;
    std::cout << std::is_same<RemoveByType<list1, double >::type, Create<int, float, int, char >::type>::value << std::endl;
    std::cout << std::is_same<RemoveByType<list2, char >::type, list2>::value << std::endl;
    std::cout << std::is_same<RemoveByType<list3, int >::type, Create<float, double, float >::type>::value << std::endl;
}

void remove_by_index() {
    using list = Create<int, float, double, int, char >::type;
    std::cout << std::is_same<RemoveByIndex<list, 0 >::type, Create<float, double, int, char >::type>::value << std::endl;
    std::cout << std::is_same<RemoveByIndex<list, 1 >::type, Create<int, double, int, char >::type>::value << std::endl;
    std::cout << std::is_same<RemoveByIndex<list, 4 >::type, Create<int, float, double, int >::type>::value << std::endl;
    std::cout << std::is_same<RemoveByIndex<list, 10 >::type, list>::value << std::endl;
}

void join() {
    using list1 = Create<int, float, double, int, char >::type;
    using list2 = Create<int, float, double, int, char >::type;
    std::cout << std::is_same<Join<list1, list2 >::type, Create<int, float, double, int, char, int, float, double, int, char>::type>::value << std::endl;
}

void insert() {
    using list1 = Create<int, float, double, int, char >::type;
    std::cout << std::is_same<Insert<list1, 0, int >::type, Create<int, int, float, double, int, char>::type>::value << std::endl;
    std::cout << std::is_same<Insert<list1, 1, char >::type, Create<int, char, float, double, int, char>::type>::value << std::endl;
    std::cout << std::is_same<Insert<list1, 5, int >::type, Create<int, float, double, int, char, int>::type>::value << std::endl;
    std::cout << std::is_same<Insert<list1, 10, int >::type, Create<int, float, double, int, char, int>::type>::value << std::endl;
}

int main() {
    replace_by_type();
    replace_by_index();
    index_of();
    find();
    length();
    remove_by_type();
    remove_by_index();
    join();
    insert();
}