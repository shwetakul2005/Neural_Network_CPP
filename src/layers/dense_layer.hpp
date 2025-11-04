#pragma once
#include "layer.hpp"
#include "../core/matrix.hpp"
#include "../activations/activation.hpp"   // if you plan to attach an activation function inside

class Dense : public Layer {
private:
    Matrix weights_;     // shape: [input_dim, output_dim]
    Matrix biases_;      // shape: [1, output_dim]
    Matrix input_;       // cache of input during forward pass

    Matrix grad_weights_;
    Matrix grad_biases_;

public:
    // Constructor
    Dense(int input_size, int output_size, const std::string& activation_type);

    // Core layer interface (must override)
    Matrix forward(const Matrix& input) override;
    Matrix backward(const Matrix& grad_output) override;
    void update(double learning_rate) override;
    
};
