# Neural Network from Scratch in C++

## 1. Introduction
This project presents the implementation of a **feedforward neural network from scratch using C++**, without relying on any external machine learning libraries.  
The primary objective is to understand and demonstrate the mathematical foundations and algorithmic structure of artificial neural networks, including **forward propagation**, **backpropagation**, and **gradient descent** optimization.

The design follows **modular and object-oriented principles**, ensuring clarity, scalability, and reusability of components such as layers, activation functions, and loss functions.

---

## 2. Objectives
The main goals of this project are:
- To implement the complete working pipeline of a neural network in C++ from first principles.  
- To understand the mathematical concepts underlying neural networks.  
- To design a modular and extensible architecture that supports multiple layers, activation functions, and loss functions.  

---

## 3. System Features
- Implementation of **forward and backward propagation** for supervised learning.  
- Support for **multiple activation functions**: Sigmoid, ReLU, and Tanh.  
- Support for **loss functions** such as Mean Squared Error (MSE) and Cross-Entropy.  
- **Gradient Descent Optimization** for parameter updates.  
- Modular and extensible structure allowing easy addition of new components.  
- Demonstrated training on the **XOR problem** to verify correctness and learning behavior.  

---

## 4. System Architecture
The project is organized into modular components as shown below:
```
NeuralNetwork/
│
├── activations/
│ ├── activation.hpp
│ ├── sigmoid.hpp
│ ├── relu.hpp
│ └── tanh.hpp
│
├── layers/
│ ├── layer.hpp
│ └── dense_layer.hpp
│
├── losses/
│ ├── loss.hpp
│ └── mse.hpp
│
|── network/
| ├── neural_network.hpp
| └── main.cpp
└── README.md
```

Each component has a specific responsibility:
- **Layers:** Define the structure and computations within each neural network layer.  
- **Activations:** Implement non-linear transformations for neuron outputs.  
- **Losses:** Measure the discrepancy between predicted and true values.  
- **Neural Network Core:** Manages the overall training and inference process.  

---

## 5. Methodology

### 5.1 Forward Propagation
Each layer computes the output as:

`z = W * x + b`  
`a = f(z)`

where `f` is the activation function (e.g., Sigmoid or ReLU).

### 5.2 Loss Computation
The network’s output is compared with target values using a chosen loss function, such as:

`L = (1/n) * Σ (y_pred - y_true)²`

### 5.3 Backpropagation
Gradients of the loss function are computed with respect to each parameter using the chain rule:

`∂L/∂W = (∂L/∂a) · (∂a/∂z) · (∂z/∂W)`

These gradients are used to update weights and biases.

### 5.4 Gradient Descent
Parameters are updated iteratively as:

`W = W - η * (∂L/∂W)`

where `η` is the learning rate.

---

## 6. Implementation Example

### 6.1 XOR Problem
The XOR dataset is a standard test case for evaluating a neural network’s ability to learn non-linear relationships.

#### Example Code:
```cpp
#include "neural_network.hpp"
#include "layers/dense_layer.hpp"
#include "activations/sigmoid.hpp"
#include "losses/mse.hpp"

int main() {
    NeuralNetwork nn(0.1); // learning rate

    nn.addLayer(new DenseLayer(2, 3, new Sigmoid()));
    nn.addLayer(new DenseLayer(3, 1, new Sigmoid()));

    std::vector<std::vector<double>> X = {
        {0, 0}, {0, 1}, {1, 0}, {1, 1}
    };
    std::vector<std::vector<double>> y = {
        {0}, {1}, {1}, {0}
    };

    nn.train(X, y, 5000);

    for (auto &input : X) {
        std::vector<double> output = nn.predict(input);
        std::cout << input[0] << " XOR " << input[1] << " = " << output[0] << std::endl;
    }
}
```
---

## 7. Build and Execution

### Compilation:
#### Use the following command to compile all C++ source files recursively:
#### For PowerShell (Windows):
```
g++ (Get-ChildItem -Recurse -Filter *.cpp | ForEach-Object { $_.FullName }) -o main
```
#### Linux/Mac users, use the equivalent:
```
g++ $(find . -name "*.cpp") -o main
```

### Execution:
```
./main
```
---

## 8. Conclusion

This project provided an in-depth understanding of the inner workings of neural networks and their implementation from scratch.
By constructing each component manually, it bridges the gap between theoretical understanding and practical implementation.
It also demonstrates how high-level frameworks (such as TensorFlow or PyTorch) function internally.

---



