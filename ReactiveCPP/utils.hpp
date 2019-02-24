//
// Created by daddabarba on 2/2/19.
//

#ifndef REACT_UTILS_H
#define REACT_UTILS_H

#include "Defs.hpp"

SEQ_START

template<int... Is>
struct seq { };

template<int N, int... Is>
struct gen_seq : gen_seq<N - 1, N - 1, Is...> { };

template<int... Is>
struct gen_seq<0, Is...> : seq<Is...> { };

SEQ_END

#endif //REACT_UTILS_H
