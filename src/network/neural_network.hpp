#pragma once
#include <iostream>
#include "../layers/layer.hpp"
#include "../layers/dense_layer.hpp"
#include "../activations/activation.hpp"
#include "../activations/sigmoid.hpp"
#include "../activations/tanh.hpp"
#include "../activations/relu.hpp"
#include "../losses/loss.hpp"


class NeuralNetwork {
private:
    std::vector<Layer*> layers_;
    Loss* loss_;
    // Optimizer* optimizer;

public:
    void addLayer(Layer* layer);
    Matrix predict(const Matrix& input);
    void compile(Loss* lossFunc);
    void train(const Matrix& X, const Matrix& Y, int epochs);
};