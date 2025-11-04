// #pragma once is a preprocessor directive in C and C++ that ensures a header file is 
// included only once per compilation, even if it’s included multiple times in different files.
#pragma once
#include <vector>
#include <iostream>

class Matrix {
private:
    int rows_, cols_;
    std::vector<std::vector<double>> data_;

public:
    // Constructors
    Matrix();
    Matrix(int rows, int cols);
    Matrix(int rows, int cols, double init_value);
    Matrix(const std::vector<std::vector<double>>& values);

    // Getters
    int rows() const;
    int cols() const;
    std::vector<std::vector<double>> getData() const;

    // Element access
    double& operator()(int r, int c);
    const double& operator()(int r, int c) const;

    // Basic operations
    Matrix transpose() const;
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;      // matrix × matrix
    Matrix operator*(double scalar) const;            // matrix × scalar
    Matrix dot(const Matrix& other) const;            // element-wise multiply
    Matrix sum(int axis) const;

    // Utilities
    void fill(double value);
    void randomize(double min = -1.0, double max = 1.0);
    void print() const;
};
