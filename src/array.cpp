#include "array.hpp"

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

int Array::getRows() const {
    return rows_;
}

int Array::getCols() const {
    return cols_;
}

double& Array::operator()(int row, int col) {
    return data_[row][col];
}

double Array::operator()(int row, int col) const {
    return data_[row][col];
}
