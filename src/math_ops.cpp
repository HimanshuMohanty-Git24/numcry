#include "math_ops.hpp"
#include <stdexcept>
#include <algorithm>
#include <cmath>

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

Array MathOps::elementWiseMultiply(const Array& a, const Array& b) {
    if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
        throw std::invalid_argument("Arrays must have the same dimensions for element-wise multiplication.");
    }

    Array result(a.getRows(), a.getCols());
    for (int i = 0; i < a.getRows(); ++i) {
        for (int j = 0; j < a.getCols(); ++j) {
            result(i, j) = a(i, j) * b(i, j);
        }
    }
    return result;
}

double MathOps::sum(const Array& a) {
    double total = 0;
    for (int i = 0; i < a.getRows(); ++i) {
        for (int j = 0; j < a.getCols(); ++j) {
            total += a(i, j);
        }
    }
    return total;
}

double MathOps::mean(const Array& a) {
    return sum(a) / (a.getRows() * a.getCols());
}

Array MathOps::divide(const Array& a, const Array& b) {
    if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
        throw std::invalid_argument("Arrays must have the same dimensions for division.");
    }
    Array result(a.getRows(), a.getCols());
    for (int i = 0; i < a.getRows(); ++i) {
        for (int j = 0; j < a.getCols(); ++j) {
            if (b(i, j) == 0) {
                throw std::runtime_error("Division by zero encountered.");
            }
            result(i, j) = a(i, j) / b(i, j);
        }
    }
    return result;
}

double MathOps::median(const Array& a) {
    std::vector<double> values;
    for (int i = 0; i < a.getRows(); ++i) {
        for (int j = 0; j < a.getCols(); ++j) {
            values.push_back(a(i, j));
        }
    }
    std::sort(values.begin(), values.end());
    int size = values.size();
    if (size % 2 == 0) {
        return (values[size / 2 - 1] + values[size / 2]) / 2.0;
    } else {
        return values[size / 2];
    }
}

double MathOps::standardDeviation(const Array& a) {
    double avg = mean(a);
    double sum_sq_diff = 0.0;
    int total_elements = a.getRows() * a.getCols();
    
    for (int i = 0; i < a.getRows(); ++i) {
        for (int j = 0; j < a.getCols(); ++j) {
            double diff = a(i, j) - avg;
            sum_sq_diff += diff * diff;
        }
    }
    
    return std::sqrt(sum_sq_diff / total_elements);
}

Array MathOps::power(const Array& a, double exponent) {
    Array result(a.getRows(), a.getCols());
    for (int i = 0; i < a.getRows(); ++i) {
        for (int j = 0; j < a.getCols(); ++j) {
            result(i, j) = std::pow(a(i, j), exponent);
        }
    }
    return result;
}

Array MathOps::exponential(const Array& a) {
    Array result(a.getRows(), a.getCols());
    for (int i = 0; i < a.getRows(); ++i) {
        for (int j = 0; j < a.getCols(); ++j) {
            result(i, j) = std::exp(a(i, j));
        }
    }
    return result;
}

Array MathOps::logarithm(const Array& a) {
    Array result(a.getRows(), a.getCols());
    for (int i = 0; i < a.getRows(); ++i) {
        for (int j = 0; j < a.getCols(); ++j) {
            if (a(i, j) <= 0) {
                throw std::domain_error("Logarithm is undefined for non-positive numbers.");
            }
            result(i, j) = std::log(a(i, j));
        }
    }
    return result;
}

Array MathOps::absolute(const Array& a) {
    Array result(a.getRows(), a.getCols());
    for (int i = 0; i < a.getRows(); ++i) {
        for (int j = 0; j < a.getCols(); ++j) {
            result(i, j) = std::abs(a(i, j));
        }
    }
    return result;
}