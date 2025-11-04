#pragma once
#include <vector>
#include <iostream>

// basic activations
double sigmoid(double x);
double relu(double x);
double tanh_act(double x);

// derivatives
double sigmoid_derivative(double x);
double relu_derivative(double x);
double tanh_derivative(double x);

// loss functions
double mse_loss(const std::vector<double>& y_true, const std::vector<double>& y_pred);
double cross_entropy(const std::vector<double>& y_true, const std::vector<double>& y_pred);

// normalization
std::vector<double> softmax(const std::vector<double>& x);
