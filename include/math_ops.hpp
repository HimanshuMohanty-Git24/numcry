// math_ops.hpp
#ifndef MATH_OPS_HPP
#define MATH_OPS_HPP

#include "array.hpp"
#include <cmath>

namespace MathOps {
    Array add(const Array& a, const Array& b);
    Array subtract(const Array& a, const Array& b);
    Array multiply(const Array& a, const Array& b);
    Array elementWiseMultiply(const Array& a, const Array& b);
    Array divide(const Array& a, const Array& b);
    double sum(const Array& a);
    double mean(const Array& a);
    double median(const Array& a);
    double standardDeviation(const Array& a);
    Array power(const Array& a, double exponent);
    Array exponential(const Array& a);
    Array logarithm(const Array& a);
    Array absolute(const Array& a);
}

#endif // MATH_OPS_HPP