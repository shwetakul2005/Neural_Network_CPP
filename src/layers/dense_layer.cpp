#include<iostream>
#include "layer.hpp"
#include "dense_layer.hpp"
#include "../core/matrix.hpp"
#include "../activations/activation.hpp"
#include <cmath>

Dense::Dense(int input_size, int output_size, const std::string& activation_type) {
    weights_ = Matrix(input_size, output_size);   // (input_size × output_size)
    biases_  = Matrix(1, output_size, 0.0);       // (1 × output_size)
    grad_weights_ = Matrix(input_size, output_size, 0.0);
    grad_biases_  = Matrix(1, output_size, 0.0);

    double limit;
    if (activation_type == "sigmoid" || activation_type == "tanh")
        limit = std::sqrt(6.0 / (input_size + output_size));
    else if (activation_type == "relu" || activation_type == "leakyrelu")
        limit = std::sqrt(6.0 / input_size);
    else
        limit = std::sqrt(6.0 / (input_size + output_size));

    weights_.randomize(-limit, limit);
}

Matrix Dense::forward(const Matrix& input) {
    input_ = input;  // (batch_size × input_size)
    Matrix z = (input * weights_) + biases_; // batch_size × output_size)
    return z;
}


Matrix Dense::backward(const Matrix& grad_output) {
    
    grad_weights_ = (input_.transpose())*grad_output;  
    grad_biases_ = grad_output.sum(0);      
    Matrix grad_input = ((grad_output)*(weights_.transpose()));     
    return grad_input;
}

void Dense::update(double learning_rate) {
    weights_ = weights_ - (grad_weights_)*(learning_rate);
    biases_ = biases_ - (grad_biases_)*(learning_rate);
}

// int main() {

//     return 0;
// }