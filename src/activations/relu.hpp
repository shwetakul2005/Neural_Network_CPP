#pragma once
#include "activation.hpp"
#include "../core/matrix.hpp"

class ReLU : public Activation {
public:
    // --- Forward Pass ---
    Matrix forward(const Matrix& input) override;

    // --- Backward Pass ---
    Matrix backward(const Matrix& grad_output) override;

    ~ReLU() override = default;
};
