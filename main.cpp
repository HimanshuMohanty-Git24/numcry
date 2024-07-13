#include <iostream>
#include <iomanip>
#include "array.hpp"
#include "math_ops.hpp"
#include "lin_alg.hpp"

void printMenu() {
    std::cout << "\nNumCry Menu:\n"
              << "1. Basic Matrix Operations\n"
              << "2. Advanced Mathematical Operations\n"
              << "3. Linear Algebra Operations\n"
              << "4. Exit\n"
              << "Enter your choice: ";
}

void basicMatrixOperations() {
    Array a(2, 2);
    a(0, 0) = 1; a(0, 1) = 2;
    a(1, 0) = 3; a(1, 1) = 4;

    Array b(2, 2);
    b(0, 0) = 5; b(0, 1) = 6;
    b(1, 0) = 7; b(1, 1) = 8;

    std::cout << "Matrix A:\n";
    a.print();
    std::cout << "Matrix B:\n";
    b.print();

    std::cout << "A + B:\n";
    MathOps::add(a, b).print();

    std::cout << "A - B:\n";
    MathOps::subtract(a, b).print();

    std::cout << "Element-wise multiplication of A and B:\n";
    MathOps::elementWiseMultiply(a, b).print();

    std::cout << "A / B:\n";
    MathOps::divide(a, b).print();
}

void advancedMathOperations() {
    Array a(2, 2);
    a(0, 0) = 1; a(0, 1) = 2;
    a(1, 0) = 3; a(1, 1) = 4;

    std::cout << "Original matrix:\n";
    a.print();

    std::cout << "Sum: " << MathOps::sum(a) << std::endl;
    std::cout << "Mean: " << MathOps::mean(a) << std::endl;
    std::cout << "Median: " << MathOps::median(a) << std::endl;
    std::cout << "Standard Deviation: " << MathOps::standardDeviation(a) << std::endl;

    std::cout << "Power (exponent 2):\n";
    MathOps::power(a, 2).print();

    std::cout << "Exponential:\n";
    MathOps::exponential(a).print();

    std::cout << "Natural Logarithm:\n";
    MathOps::logarithm(a).print();

    std::cout << "Absolute Value:\n";
    MathOps::absolute(Array({{-1, 2}, {-3, 4}})).print();
}

void linearAlgebraOperations() {
    try {
        Array a(2, 2);
        a(0, 0) = 1; a(0, 1) = 2;
        a(1, 0) = 3; a(1, 1) = 4;

        std::cout << "Original matrix:\n";
        a.print();

        std::cout << "Transpose:\n";
        LinAlg::transpose(a).print();

        std::cout << "Matrix multiplication (A * A):\n";
        LinAlg::matrixMultiply(a, a).print();

        std::cout << "Determinant: " << LinAlg::determinant(a) << std::endl;

        std::cout << "Inverse:\n";
        LinAlg::inverse(a).print();

        std::pair<Array, Array> eigen_result = LinAlg::eigenDecomposition(a);
        std::cout << "Dominant eigenvalue: " << eigen_result.first(0, 0) << std::endl;
        std::cout << "Corresponding eigenvector:\n";
        eigen_result.second.print();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "Welcome to NumCry - NumPy in C++!\n";
    
    int choice;
    do {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "\n--- Basic Matrix Operations ---\n";
                basicMatrixOperations();
                break;
            case 2:
                std::cout << "\n--- Advanced Mathematical Operations ---\n";
                advancedMathOperations();
                break;
            case 3:
                std::cout << "\n--- Linear Algebra Operations ---\n";
                linearAlgebraOperations();
                break;
            case 4:
                std::cout << "Thank you for using NumCry. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}