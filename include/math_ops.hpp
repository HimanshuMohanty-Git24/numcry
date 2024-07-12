#ifndef MATH_OPS_HPP
#define MATH_OPS_HPP

#include "array.hpp"

namespace MathOps {
    Array add(const Array& a, const Array& b);
    Array subtract(const Array& a, const Array& b);
    Array multiply(const Array& a, const Array& b);
    Array elementWiseMultiply(const Array& a, const Array& b);
    double sum(const Array& a);
    double mean(const Array& a);
}

#endif // MATH_OPS_HPP
