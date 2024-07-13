#include "lin_alg.hpp"
#include <stdexcept>
#include <cmath>

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

Array LinAlg::matrixMultiply(const Array& a, const Array& b) {
    if (a.getCols() != b.getRows()) {
        throw std::invalid_argument("Matrix dimensions are not compatible for multiplication.");
    }
    
    Array result(a.getRows(), b.getCols());
    for (int i = 0; i < a.getRows(); ++i) {
        for (int j = 0; j < b.getCols(); ++j) {
            double sum = 0;
            for (int k = 0; k < a.getCols(); ++k) {
                sum += a(i, k) * b(k, j);
            }
            result(i, j) = sum;
        }
    }
    return result;
}

double LinAlg::determinant(const Array& a) {
    if (a.getRows() != a.getCols()) {
        throw std::invalid_argument("Matrix must be square to calculate determinant.");
    }
    
    int n = a.getRows();
    
    if (n == 1) {
        return a(0, 0);
    }
    
    if (n == 2) {
        return a(0, 0) * a(1, 1) - a(0, 1) * a(1, 0);
    }
    
    double det = 0;
    for (int j = 0; j < n; ++j) {
        Array submatrix(n - 1, n - 1);
        for (int i = 1; i < n; ++i) {
            int k = 0;
            for (int l = 0; l < n; ++l) {
                if (l != j) {
                    submatrix(i - 1, k) = a(i, l);
                    ++k;
                }
            }
        }
        det += (j % 2 == 0 ? 1 : -1) * a(0, j) * determinant(submatrix);
    }
    
    return det;
}

Array LinAlg::inverse(const Array& a) {
    if (a.getRows() != a.getCols()) {
        throw std::invalid_argument("Matrix must be square to calculate inverse.");
    }
    
    int n = a.getRows();
    double det = determinant(a);
    
    if (std::abs(det) < 1e-10) {
        throw std::runtime_error("Matrix is singular and cannot be inverted.");
    }
    
    Array result(n, n);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            Array submatrix(n - 1, n - 1);
            int r = 0;
            for (int k = 0; k < n; ++k) {
                if (k != i) {
                    int c = 0;
                    for (int l = 0; l < n; ++l) {
                        if (l != j) {
                            submatrix(r, c) = a(k, l);
                            ++c;
                        }
                    }
                    ++r;
                }
            }
            double cofactor = ((i + j) % 2 == 0 ? 1 : -1) * determinant(submatrix);
            result(j, i) = cofactor / det;
        }
    }
    
    return result;
}

std::pair<Array, Array> LinAlg::eigenDecomposition(const Array& a) {
    if (a.getRows() != a.getCols()) {
        throw std::invalid_argument("Matrix must be square for eigendecomposition.");
    }
    
    int n = a.getRows();
    Array v(n, 1);
    for (int i = 0; i < n; ++i) {
        v(i, 0) = 1.0 / std::sqrt(n);
    }
    
    double eigenvalue = 0;
    for (int iter = 0; iter < 100; ++iter) {
        Array w = matrixMultiply(a, v);
        double new_eigenvalue = w(0, 0) / v(0, 0);
        if (std::abs(new_eigenvalue - eigenvalue) < 1e-10) {
            break;
        }
        eigenvalue = new_eigenvalue;
        double norm = 0;
        for (int i = 0; i < n; ++i) {
            norm += w(i, 0) * w(i, 0);
        }
        norm = std::sqrt(norm);
        for (int i = 0; i < n; ++i) {
            v(i, 0) = w(i, 0) / norm;
        }
    }
    
    Array eigenvalue_array(1, 1);
    eigenvalue_array(0, 0) = eigenvalue;
    return std::make_pair(eigenvalue_array, v);
}
