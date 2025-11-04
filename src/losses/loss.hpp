#pragma once
#include <iostream>
#include "../core/math_utils.hpp"
#include "../core/matrix.hpp"

class Loss {
    public:
    virtual double forward(const Matrix& predictions, const Matrix& targets) = 0;
    virtual Matrix backward(const Matrix& predictions, const Matrix& targets) = 0;

    virtual ~Loss() = default;
    
};