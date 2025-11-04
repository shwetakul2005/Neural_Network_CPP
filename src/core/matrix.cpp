#include "matrix.hpp"
#include <iostream>
#include<vector>
#include <cassert>
#include <random>
#include "random.hpp"
// using namespace std;

// --initializes empty matrix(default constructor)
Matrix::Matrix() {
    rows_ = 0;
    cols_ = 0;
}

//  --initializes a matrix of size rowsxcols with all values = 0
Matrix::Matrix(int rows, int cols) {
    rows_ = rows;
    cols_ = cols;
    data_ = std::vector<std::vector<double>>(rows, std::vector<double>(cols,0.0));
}

//  --initializes a matrix of size rowsxcols with all values = val
Matrix::Matrix(int rows, int cols, double val) {
    rows_ = rows;
    cols_ = cols;
    data_ = std::vector<std::vector<double>>(rows, std::vector<double>(cols,val));
}

//  --initializes a matrix of size and values = values vector
Matrix::Matrix(const std::vector<std::vector<double>>& values) {
    rows_ = values.size();
    cols_ = values.empty() ? 0 : values[0].size();
    data_ = values;
}

int Matrix::rows() const{
    return rows_;
}

int Matrix::cols() const{
    return cols_;
}

std::vector<std::vector<double>> Matrix::getData() const{
    return data_;
}

double& Matrix::operator()(int r, int c) { 
    assert(r >= 0 && r < rows_ && c >= 0 && c < cols_ && "Matrix index out of range");
    return data_[r][c];
}

// const double& Matrix::operator()(int r, int c) { 
//     assert(r >= 0 && r < rows_ && c >= 0 && c < cols_ && "Matrix index out of range");
//     return data_[r][c];
// }

Matrix Matrix::transpose() const {
    if (rows_ == 0 || cols_ == 0) {
        return Matrix(); // empty
    }

    std::vector<std::vector<double>> data_new(cols_, std::vector<double>(rows_));

    for (int i=0; i<rows_; i++) {
        for (int j=0; j<cols_; j++){
            data_new[j][i] = data_[i][j];
        }
    }
    return Matrix(data_new);     
}

// Matrix Matrix::operator+(const Matrix& other) const {
//     assert(rows_ == other.rows_ && cols_ == other.cols_ && "Matrix size mismatch");
//     std::vector<std::vector<double>> data_new(rows_, std::vector<double>(cols_));

//     for (int i=0; i<rows_; i++) {
//         for (int j=0; j<cols_; j++){
//             data_new[i][j] = data_[i][j] + other.data_[i][j];
//         }
//     }
//     return Matrix(data_new);
    
// }

Matrix Matrix::operator+(const Matrix& other) const {
    bool same_shape = (rows_ == other.rows_ && cols_ == other.cols_);
    bool col_broadcast = (rows_ == other.rows_ && other.cols_ == 1);
    bool row_broadcast = (cols_ == other.cols_ && other.rows_ == 1);

    assert((same_shape || col_broadcast || row_broadcast) && "Matrix size mismatch");

    std::vector<std::vector<double>> result(rows_, std::vector<double>(cols_));

    for (size_t i = 0; i < rows_; ++i) {
        for (size_t j = 0; j < cols_; ++j) {
            double val;
            if (same_shape) val = other.data_[i][j];
            else if (col_broadcast) val = other.data_[i][0];   // broadcast down columns
            else val = other.data_[0][j];                      // broadcast across rows
            result[i][j] = data_[i][j] + val;
        }
    }

    return Matrix(result);
}



Matrix Matrix::operator-(const Matrix& other) const {
    assert(rows_ == other.rows_ && cols_ == other.cols_ && "Matrix size mismatch");
    std::vector<std::vector<double>> data_new(rows_, std::vector<double>(cols_));

    for (int i=0; i<rows_; i++) {
        for (int j=0; j<cols_; j++){
            data_new[i][j] = data_[i][j] - other.data_[i][j];
        }
    }
    return Matrix(data_new);
}
Matrix Matrix::operator*(const Matrix& other) const {
    // std::cout << "Multiplying matrices: (" << rows_ << "x" << cols_ 
    //           << ") * (" << other.rows_ << "x" << other.cols_ << ")\n";
    assert(cols_ == other.rows_&& "Matrix size mismatch for multiplication");
    std::vector<std::vector<double>> data_new(rows_, std::vector<double>(other.cols_));

    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < other.cols_; ++j) {
            double num = 0.0; // initialize per column computation
            for (int k = 0; k < cols_; ++k) {
                num += data_[i][k] * other.data_[k][j];
            }
            data_new[i][j] = num;
        }
    }

    return Matrix(data_new);
}
Matrix Matrix::operator*(double scalar) const { 
    if (rows_ == 0 || cols_ == 0) {
        return Matrix();  // return empty
    }
    std::vector<std::vector<double>> data_new(rows_, std::vector<double>(cols_));
    for (int i=0; i<rows_; i++) {
        for (int j=0; j<cols_; j++){
            data_new[i][j] = data_[i][j] * scalar;
        }
    }
    return Matrix(data_new);
}

Matrix Matrix::dot(const Matrix& other) const {
    assert(rows_ == other.rows_ && cols_ == other.cols_ && "Matrix size mismatch");
    std::vector<std::vector<double>> data_new(rows_, std::vector<double>(cols_));

    for (int i=0; i<rows_; i++) {
        for (int j=0; j<cols_; j++){
            data_new[i][j] = data_[i][j] * other.data_[i][j];
        }
    }
    return Matrix(data_new);
}

Matrix Matrix::sum(int axis) const {
    assert((axis == 0 || axis == 1) && "Axis entered incorrectly.");
    if(axis==0){
        std::vector<std::vector<double>> data_new_a0(1, std::vector<double>(cols_));
        for (int i=0; i<rows_; i++) {
            for (int j=0; j<cols_; j++){
                data_new_a0[0][j] += data_[i][j];
            }
        }   
        return Matrix(data_new_a0); 
    }
    else if(axis==1) {
        std::vector<std::vector<double>> data_new_a1(rows_, std::vector<double>(1));
        for (int i=0; i<rows_; i++) {
            for (int j=0; j<cols_; j++){
                data_new_a1[i][0] += data_[i][j];
            }
        }
        return Matrix(data_new_a1);
    }
    return Matrix();
} 


void Matrix::fill(double value) {
    for (int i=0; i<rows_; i++) {
        for (int j=0; j<cols_; j++){
            data_[i][j] = value;
        }
    }
}

void Matrix::randomize(double min, double max) {
    Matrix randM = random_matrix(rows_, cols_, min, max);
    data_ = randM.getData();
}

void Matrix::print() const {
    for (auto &row : data_) {
        for (auto &val : row)
            std::cout << val << " ";
        std::cout << "\n";
    }
    std::cout<<"->Size of the matrix is "<<rows_<<"x"<<cols_<<"\n";
}
// int main() {
//     // std::vector<std::vector<double>> data(3, std::vector<double>(4, 0.0));
//     // for (auto &row : data) {
//     //     for (auto &val : row)
//     //         std::cout << val << " ";
//     //     std::cout << "\n";
//     // }
//     Matrix a = Matrix(3,4,2.0);
//     Matrix c = Matrix(3,4,6.0);
//     a.fill(8.0);
//     a.print();
//     // Matrix b = a.dot(c);
//     // b.print();
//     return 0;
    
// }