#include "matrix.hpp"
#include <iostream>
#include<vector>
#include <cassert>
#include <random>
#include <cmath>

// basic activations
double sigmoid(double x){
    return (1/1+exp(-1));
};
double relu(double x){
    if(x > 0){
        return x;
    }
    return 0;
};
double tanh_act(double x){
    return std::tanh(x);
};

// derivatives
double sigmoid_derivative(double x){
    return ((sigmoid(x)*(1-sigmoid(x))));
};
double relu_derivative(double x){
    if(x>0){
        return 1;
    }
    return 0;
};
double tanh_derivative(double x){
    double sech = (1.0 / std::cosh(x));
    return (sech * sech);
};

// loss functions
double mse_loss(const std::vector<double>& y_true, const std::vector<double>& y_pred){
    assert(y_true.size() == y_pred.size() && "Vectors must be of same size");
    double sum = 0.0;
    for (size_t  i = 0; i < y_true.size(); ++i) {
        double diff = y_true[i] - y_pred[i];
        sum += diff * diff;
    }
    return 0.5 * sum / y_true.size();
};
double cross_entropy(const std::vector<double>& y_true, const std::vector<double>& y_pred){
    assert(y_true.size() == y_pred.size() && "Vectors must be of same size");
    double sum = 0.0;
    for (size_t  i = 0; i < y_true.size(); ++i) {
        double mul = y_true[i] * std::log(y_pred[i]);
        sum += mul;
    }
    return (-1 * sum);
};

// normalization
std::vector<double> softmax(const std::vector<double>& x);