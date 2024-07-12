#ifndef LIN_ALG_HPP
#define LIN_ALG_HPP

#include "array.hpp"

namespace LinAlg {
    double dot(const Array& a, const Array& b);
    Array transpose(const Array& a);
}

#endif // LIN_ALG_HPP
