#include "array.hpp"
#include <stdexcept>
#include <numeric>

Array::Array(int rows, int cols) : rows_(rows), cols_(cols), data_(rows, std::vector<double>(cols, 0)) {}

Array::Array(const std::vector<std::vector<double>>& data) : data_(data), rows_(data.size()), cols_(data[0].size()) {}

void Array::print() const {
    for (const auto& row : data_) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

int Array::getRows() const { return rows_; }
int Array::getCols() const { return cols_; }

double& Array::operator()(int row, int col) { return data_[row][col]; }
double Array::operator()(int row, int col) const { return data_[row][col]; }

Array Array::reshape(int newRows, int newCols) const {
    if (newRows * newCols != rows_ * cols_) {
        throw std::invalid_argument("New dimensions must match the size of the original array.");
    }
    Array result(newRows, newCols);
    int index = 0;
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            result(index / newCols, index % newCols) = data_[i][j];
            ++index;
        }
    }
    return result;
}

Array Array::flatten() const {
    return reshape(1, rows_ * cols_);
}
