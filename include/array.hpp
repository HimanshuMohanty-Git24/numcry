#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <vector>
#include <iostream>

class Array {
public:
    Array(int rows, int cols);
    Array(const std::vector<std::vector<double>>& data);

    void print() const;

    int getRows() const;
    int getCols() const;
    double& operator()(int row, int col);
    double operator()(int row, int col) const;

private:
    std::vector<std::vector<double>> data_;
    int rows_;
    int cols_;
};

#endif // ARRAY_HPP
