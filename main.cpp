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

    return 0;
}
