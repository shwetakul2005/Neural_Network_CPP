#include <iostream>
#include "../core/math_utils.hpp"
#include "../core/matrix.hpp"
#include "loss.hpp"
#include "cross_entropy_loss.hpp"
#include <cassert>

double CEloss::forward(const Matrix& predictions, const Matrix& targets){
    assert(predictions.rows() == targets.rows() && "Size mismatch.");
    double loss_value=0.0;
    for(int i=0; i<predictions.rows(); i++){
        loss_value  = cross_entropy(targets.getData()[i], predictions.getData()[i]);
    }
    return loss_value;
}

Matrix CEloss::backward(const Matrix& predictions, const Matrix& targets) {
    assert((predictions.rows() == targets.rows() && predictions.cols() == targets.cols()) && "Size mismatch.");
    
    double scale = 1.0 / static_cast<double>(targets.rows());
    Matrix c = ((predictions - targets)*(scale));
    return c;
}