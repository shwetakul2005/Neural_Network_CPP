#pragma once
#include "../layers/layer.hpp"
#include "optimizer.hpp"
#include <unordered_map>

class Adam : public Optimizer {
private:
    double beta1_;
    double beta2_;
    double epsilon_;
    int t_;

    std::unordered_map<Layer*, Matrix> m_weights_, v_weights_;
    std::unordered_map<Layer*, Matrix> m_biases_, v_biases_;

public:
    Adam(double lr = 0.001, double beta1 = 0.9, double beta2 = 0.999, double epsilon = 1e-8);

    void step(Layer& layer) override;
};
