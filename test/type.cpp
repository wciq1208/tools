//
// Created by wciq1208 on 19-10-29.
//

#include "list.h"
#include "map.h"
#include <iostream>

using namespace type;

void list_replace_by_type() {
    using list1 = list::Creator<int, float, double, int, float >::type;
    std::cout << std::is_same<list::ReplaceByType<list1, int , char>::type, list::Creator<char, float, double, char, float >::type>::value << std::endl;
    std::cout << std::is_same<list::ReplaceByType<list1, char , int>::type, list1>::value << std::endl;
    std::cout << std::is_same<list::ReplaceByType<list1, float , int>::type, list::Creator<int, int, double, int, int >::type>::value << std::endl;
}

void list_replace_by_index() {
    using list1 = list::Creator<int, float, double, int, float >::type;
    std::cout << std::is_same<list::ReplaceByIndex<list1, 0, char >::type, list::Creator<char, float, double, int, float >::type>::value << std::endl;
    std::cout << std::is_same<list::ReplaceByIndex<list1, 0, int >::type, list1>::value << std::endl;
    std::cout << std::is_same<list::ReplaceByIndex<list1, 1, char >::type, list::Creator<int, char, double, int, float >::type>::value << std::endl;
    std::cout << std::is_same<list::ReplaceByIndex<list1, 4, char >::type, list::Creator<int, float, double, int, char >::type>::value << std::endl;
    std::cout << std::is_same<list::ReplaceByIndex<list1, 10, char >::type, list1>::value << std::endl;
}

void list_index_of() {
    using list1 = list::Creator<int, float, double, int, float >::type;
    std::cout << std::is_same<list::IndexOf<list1, 1>::type, float>::value << std::endl;
    std::cout << std::is_same<list::IndexOf<list1, 0>::type, int>::value << std::endl;
    std::cout << std::is_same<list::IndexOf<list1, 4>::type, float>::value << std::endl;
}

void list_find() {
    using list1 = list::Creator<int, float, double, int, char >::type;
    std::cout << (list::Find<list1, float>::value == 1) << std::endl;
    std::cout << (list::Find<list1, int>::value == 0) << std::endl;
    std::cout << (list::Find<list1, char>::value == 4) << std::endl;
    std::cout << (list::Find<list1, bool >::value == -1) << std::endl;
}

void list_length() {
    using list1 = list::Creator<int, float, double, int, char >::type;
    using list2 = list::Creator<int>::type;
    std::cout << (list::Length<list1>::value == 5) << std::endl;
    std::cout << (list::Length<list2>::value == 1) << std::endl;
}

void list_remove_by_type() {
    using list1 = list::Creator<int, float, double, int, char >::type;
    using list2 = list::Creator<int, float, double, int, float >::type;
    using list3 = list::Creator<int, float, double, int, float >::type;
    std::cout << std::is_same<list::RemoveByType<list1, double >::type, list::Creator<int, float, int, char >::type>::value << std::endl;
    std::cout << std::is_same<list::RemoveByType<list2, char >::type, list2>::value << std::endl;
    std::cout << std::is_same<list::RemoveByType<list3, int >::type, list::Creator<float, double, float >::type>::value << std::endl;
}

void list_remove_by_index() {
    using list1 = list::Creator<int, float, double, int, char >::type;
    std::cout << std::is_same<list::RemoveByIndex<list1, 0 >::type, list::Creator<float, double, int, char >::type>::value << std::endl;
    std::cout << std::is_same<list::RemoveByIndex<list1, 1 >::type, list::Creator<int, double, int, char >::type>::value << std::endl;
    std::cout << std::is_same<list::RemoveByIndex<list1, 4 >::type, list::Creator<int, float, double, int >::type>::value << std::endl;
    std::cout << std::is_same<list::RemoveByIndex<list1, 10 >::type, list1>::value << std::endl;
}

void list_join() {
    using list1 = list::Creator<int, float, double, int, char >::type;
    using list2 = list::Creator<int, float, double, int, char >::type;
    std::cout << std::is_same<list::Join<list1, list2 >::type, list::Creator<int, float, double, int, char, int, float, double, int, char>::type>::value << std::endl;
}

void list_insert() {
    using list1 = list::Creator<int, float, double, int, char >::type;
    std::cout << std::is_same<list::Insert<list1, 0, int >::type, list::Creator<int, int, float, double, int, char>::type>::value << std::endl;
    std::cout << std::is_same<list::Insert<list1, 1, char >::type, list::Creator<int, char, float, double, int, char>::type>::value << std::endl;
    std::cout << std::is_same<list::Insert<list1, 5, int >::type, list::Creator<int, float, double, int, char, int>::type>::value << std::endl;
    std::cout << std::is_same<list::Insert<list1, 10, int >::type, list::Creator<int, float, double, int, char, int>::type>::value << std::endl;
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

void map_remove() {
    struct Test1;
    struct Test2;
    using map1 = map::Creator<
        Pair<int, float>,
        Pair<float, char>,
        Pair<Test1, Test2>,
        Pair<long, short>>::type;
    std::cout << std::is_same<map::Get<map::Remove<map1, float>::type, float >::type , Empty>::value << std::endl;
    std::cout << std::is_same<map::Get<map::Remove<map1, char>::type, char >::type , Empty>::value << std::endl;
}

void map_no_duplicate() {
    struct Test1;
    struct Test2;
    using map1 = map::Creator<
        Pair<int, float>,
        Pair<int, char>,
        Pair<int, Test2>,
        Pair<int, short>>::type;
    std::cout << std::is_same<map::Get<map1, int >::type , float>::value << std::endl;
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
    map_remove();
}