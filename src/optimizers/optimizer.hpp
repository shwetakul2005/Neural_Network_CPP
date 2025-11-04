#pragma once
#include "../layers/layer.hpp"

class Optimizer {
protected:
    double learning_rate_;

public:
    Optimizer(double lr) : learning_rate_(lr) {}

    // Apply optimization step to a layer
    virtual void step(Layer& layer) = 0;

    virtual ~Optimizer() = default;
};
