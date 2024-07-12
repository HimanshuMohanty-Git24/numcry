#include "lin_alg.hpp"
#include <stdexcept>

double LinAlg::dot(const Array& a, const Array& b) {
    if (a.getCols() != b.getCols() || a.getRows() != b.getRows() || a.getRows() != 1) {
        throw std::invalid_argument("Arrays must be vectors of the same length for dot product.");
    }

    double result = 0;
    for (int i = 0; i < a.getCols(); ++i) {
        result += a(0, i) * b(0, i);
    }
    return result;
}

Array LinAlg::transpose(const Array& a) {
    Array result(a.getCols(), a.getRows());
    for (int i = 0; i < a.getRows(); ++i) {
        for (int j = 0; j < a.getCols(); ++j) {
            result(j, i) = a(i, j);
        }
    }
    return result;
}
