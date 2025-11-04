#include <iostream>
#include "../core/math_utils.hpp"
#include "../core/matrix.hpp"
#include "sigmoid.hpp"


Matrix Sigmoid::forward(const Matrix& input) {
    input_ = input;
    std::vector<std::vector<double>> data_new(input.rows(), std::vector<double>(input.cols()));
    for(int i=0; i<input.rows(); i++){
        for(int j =0; j<input.cols(); j++){
            data_new[i][j] = sigmoid(input.getData()[i][j]);
        }
    }
    return Matrix(data_new);
}

Matrix Sigmoid::backward(const Matrix& grad_output) {
    std::vector<std::vector<double>> data_new(grad_output.rows(), std::vector<double>(grad_output.cols()));
    for(int i=0; i<grad_output.rows(); i++){
        for(int j =0; j<grad_output.cols(); j++){
            double grad_wrt_acti = sigmoid_derivative(input_.getData()[i][j]);
            data_new[i][j] = grad_output.getData()[i][j] * grad_wrt_acti;
        }
    }
    return Matrix(data_new);
}