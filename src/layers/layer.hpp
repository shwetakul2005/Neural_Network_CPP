#pragma once
#include "../core/matrix.hpp"

class Layer {
protected:
    bool train_mode_ = true;     // tracks whether we’re training or evaluating

public:
    // --- Core Interface ---
    virtual Matrix forward(const Matrix& input) = 0;        // Forward pass (not declared in layer.cpp)
    virtual Matrix backward(const Matrix& grad_output) = 0; // Backward pass (not declared in layer.cpp)

    // --- Optional Interface (for trainable layers) ---
    virtual void update(double learning_rate) {}             // Update params if any (not declared in layer.cpp)

    // --- Utility ---
    void set_train(bool mode);                               // Set train/eval mode
    bool is_training() const;
    virtual ~Layer() = default;                              // Virtual destructor for polymorphism
};

// Layer is an interface or blueprint for all layers in the network:
//      -> It tells every layer: “you must define how to do forward and backward passes.”
//      -> But it doesn’t say how — that’s left to derived classes.
// Layer class is an abstract class as it has atleast 1 pure virtual function (forward and backward)