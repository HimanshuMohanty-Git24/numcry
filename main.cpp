#include <iostream>
#include "array.hpp"
#include "math_ops.hpp"
#include "lin_alg.hpp"

int main() {
    Array a(2, 2);
    a(0, 0) = 1;
    a(0, 1) = 2;
    a(1, 0) = 3;
    a(1, 1) = 4;

    Array b(2, 2);
    b(0, 0) = 5;
    b(0, 1) = 6;
    b(1, 0) = 7;
    b(1, 1) = 8;

    Array c = MathOps::add(a, b);
    Array d = MathOps::subtract(a, b);
    Array e = MathOps::multiply(a, b);
    Array f = LinAlg::transpose(a);
    Array g = MathOps::elementWiseMultiply(a, b);
    Array h = a.flatten();

    std::cout << "Matrix A:" << std::endl;
    a.print();
    std::cout << "Matrix B:" << std::endl;
    b.print();
    std::cout << "A + B:" << std::endl;
    c.print();
    std::cout << "A - B:" << std::endl;
    d.print();
    std::cout << "A * B:" << std::endl;
    e.print();
    std::cout << "Transpose of A:" << std::endl;
    f.print();
    std::cout << "Element-wise A * B:" << std::endl;
    g.print();
    std::cout << "Flattened A:" << std::endl;
    h.print();
    std::cout << "Sum of A: " << MathOps::sum(a) << std::endl;
    std::cout << "Mean of A: " << MathOps::mean(a) << std::endl;

    return 0;
}
