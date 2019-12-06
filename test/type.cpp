//
// Created by wciq1208 on 19-10-29.
//

#include "list.h"
#include "map.h"
#include <iostream>

using namespace type;
using namespace type::list;

void list_replace_by_type() {
    using list = Creator<int, float, double, int, float >::type;
    std::cout << std::is_same<ReplaceByType<list, int , char>::type, Creator<char, float, double, char, float >::type>::value << std::endl;
    std::cout << std::is_same<ReplaceByType<list, char , int>::type, list>::value << std::endl;
    std::cout << std::is_same<ReplaceByType<list, float , int>::type, Creator<int, int, double, int, int >::type>::value << std::endl;
}

void list_replace_by_index() {
    using list = Creator<int, float, double, int, float >::type;
    std::cout << std::is_same<ReplaceByIndex<list, 0, char >::type, Creator<char, float, double, int, float >::type>::value << std::endl;
    std::cout << std::is_same<ReplaceByIndex<list, 0, int >::type, list>::value << std::endl;
    std::cout << std::is_same<ReplaceByIndex<list, 1, char >::type, Creator<int, char, double, int, float >::type>::value << std::endl;
    std::cout << std::is_same<ReplaceByIndex<list, 4, char >::type, Creator<int, float, double, int, char >::type>::value << std::endl;
    std::cout << std::is_same<ReplaceByIndex<list, 10, char >::type, list>::value << std::endl;
}

void list_index_of() {
    using list = Creator<int, float, double, int, float >::type;
    std::cout << std::is_same<IndexOf<list, 1>::type, float>::value << std::endl;
    std::cout << std::is_same<IndexOf<list, 0>::type, int>::value << std::endl;
    std::cout << std::is_same<IndexOf<list, 4>::type, float>::value << std::endl;
}

void list_find() {
    using list = Creator<int, float, double, int, char >::type;
    std::cout << (Find<list, float>::value == 1) << std::endl;
    std::cout << (Find<list, int>::value == 0) << std::endl;
    std::cout << (Find<list, char>::value == 4) << std::endl;
    std::cout << (Find<list, bool >::value == -1) << std::endl;
}

void list_length() {
    using list1 = Creator<int, float, double, int, char >::type;
    using list2 = Creator<int>::type;
    std::cout << (Length<list1>::value == 5) << std::endl;
    std::cout << (Length<list2>::value == 1) << std::endl;
}

void list_remove_by_type() {
    using list1 = Creator<int, float, double, int, char >::type;
    using list2 = Creator<int, float, double, int, float >::type;
    using list3 = Creator<int, float, double, int, float >::type;
    std::cout << std::is_same<RemoveByType<list1, double >::type, Creator<int, float, int, char >::type>::value << std::endl;
    std::cout << std::is_same<RemoveByType<list2, char >::type, list2>::value << std::endl;
    std::cout << std::is_same<RemoveByType<list3, int >::type, Creator<float, double, float >::type>::value << std::endl;
}

void list_remove_by_index() {
    using list = Creator<int, float, double, int, char >::type;
    std::cout << std::is_same<RemoveByIndex<list, 0 >::type, Creator<float, double, int, char >::type>::value << std::endl;
    std::cout << std::is_same<RemoveByIndex<list, 1 >::type, Creator<int, double, int, char >::type>::value << std::endl;
    std::cout << std::is_same<RemoveByIndex<list, 4 >::type, Creator<int, float, double, int >::type>::value << std::endl;
    std::cout << std::is_same<RemoveByIndex<list, 10 >::type, list>::value << std::endl;
}

void list_join() {
    using list1 = Creator<int, float, double, int, char >::type;
    using list2 = Creator<int, float, double, int, char >::type;
    std::cout << std::is_same<Join<list1, list2 >::type, Creator<int, float, double, int, char, int, float, double, int, char>::type>::value << std::endl;
}

void list_insert() {
    using list1 = Creator<int, float, double, int, char >::type;
    std::cout << std::is_same<Insert<list1, 0, int >::type, Creator<int, int, float, double, int, char>::type>::value << std::endl;
    std::cout << std::is_same<Insert<list1, 1, char >::type, Creator<int, char, float, double, int, char>::type>::value << std::endl;
    std::cout << std::is_same<Insert<list1, 5, int >::type, Creator<int, float, double, int, char, int>::type>::value << std::endl;
    std::cout << std::is_same<Insert<list1, 10, int >::type, Creator<int, float, double, int, char, int>::type>::value << std::endl;
}


void map_get() {
    struct Test1;
    struct Test2;
    using map1 = map::Creator<
        Pair<int, float>,
        Pair<float, char>,
        Pair<Test1, Test2>,
        Pair<long, short>>::type;
    std::cout << std::is_same<map::Get<map1, float >::type, char>::value << std::endl;
    std::cout << std::is_same<map::Get<map1, double >::type, Empty>::value << std::endl;
    std::cout << std::is_same<map::Get<map1, Test1 >::type, Test2>::value << std::endl;
}

void map_set() {
    struct Test1;
    struct Test2;
    using map1 = map::Creator<
        Pair<Test1, int>>::type;
    std::cout << std::is_same<map::Get<map1, Test1 >::type, int>::value << std::endl;
    std::cout << std::is_same<map::Get<map::Set<map1, Test1, Test2>::type, Test1 >::type, Test2>::value << std::endl;
    std::cout << std::is_same<map::Get<map::Set<map1, int, char>::type, int >::type, char>::value << std::endl;
}

int main() {
    std::cout << "list test" << std::endl;
    list_replace_by_type();
    list_replace_by_index();
    list_index_of();
    list_find();
    list_length();
    list_remove_by_type();
    list_remove_by_index();
    list_join();
    list_insert();
    std::cout << "map test" << std::endl;
    map_get();
    map_set();
}