#ifndef LIN_ALG_HPP
#define LIN_ALG_HPP

#include "array.hpp"

namespace LinAlg {
    double dot(const Array& a, const Array& b);
    Array transpose(const Array& a);
    Array matrixMultiply(const Array& a, const Array& b);
    double determinant(const Array& a);
    Array inverse(const Array& a);
    std::pair<Array, Array> eigenDecomposition(const Array& a);
}

#endif // LIN_ALG_HPP