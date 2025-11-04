#pragma once
#include "loss.hpp"
#include "../core/matrix.hpp"

class MSEloss : public Loss {
public:
    // --- Forward Pass ---
    double forward(const Matrix& predictions, const Matrix& targets) override;

    // --- Backward Pass ---
    Matrix backward(const Matrix& predictions, const Matrix& targets) override;

    ~MSEloss() override = default;
};