#pragma once
#include<iostream>
#include "../core/math_utils.hpp"

class Activation {
    protected:
    Matrix input_;
    public:
        virtual Matrix forward(const Matrix& input) = 0;
        virtual Matrix backward(const Matrix& grad_output) = 0;
        
        virtual ~Activation() = default;
};
