#include "math_ops.hpp"
#include <stdexcept>

Array MathOps::add(const Array& a, const Array& b) {
    if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
        throw std::invalid_argument("Arrays must have the same dimensions for addition.");
    }

    Array result(a.getRows(), a.getCols());
    for (int i = 0; i < a.getRows(); ++i) {
        for (int j = 0; j < a.getCols(); ++j) {
            result(i, j) = a(i, j) + b(i, j);
        }
    }
    return result;
}

Array MathOps::subtract(const Array& a, const Array& b) {
    if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
        throw std::invalid_argument("Arrays must have the same dimensions for subtraction.");
    }

    Array result(a.getRows(), a.getCols());
    for (int i = 0; i < a.getRows(); ++i) {
        for (int j = 0; j < a.getCols(); ++j) {
            result(i, j) = a(i, j) - b(i, j);
        }
    }
    return result;
}

Array MathOps::multiply(const Array& a, const Array& b) {
    if (a.getCols() != b.getRows()) {
        throw std::invalid_argument("Number of columns of A must equal number of rows of B for multiplication.");
    }

    Array result(a.getRows(), b.getCols());
    for (int i = 0; i < result.getRows(); ++i) {
        for (int j = 0; j < result.getCols(); ++j) {
            for (int k = 0; k < a.getCols(); ++k) {
                result(i, j) += a(i, k) * b(k, j);
            }
        }
    }
    return result;
}
