//
// Created by wciq1208 on 19-12-6.
//

#ifndef TOOLS_TYPE_MAP_H_
#define TOOLS_TYPE_MAP_H_

#include "list.h"
#include "pair.h"

namespace type {
namespace map {

template <class ...Args>
struct Map {
    typedef list::List<Args...> type;
};

template <class ...Args>
struct MapCreator {
    typedef list::Creator<Args...> type;
};

template <class TMap, class K>
struct Find;


}
}

#endif //TOOLS_TYPE_MAP_H_
