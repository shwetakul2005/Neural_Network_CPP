#include "neural_network.hpp"
#include "../layers/dense_layer.hpp"
#include "../activations/sigmoid.hpp"
#include "../losses/mse_loss.hpp"
#include "../core/matrix.hpp"
#include <iostream>

int main() {
    
    Matrix X({{0, 0}, {0, 1}, {1, 0}, {1, 1}});
    Matrix Y({{0}, {1}, {1}, {0}}); // XOR pattern

   
    NeuralNetwork model;
    model.addLayer(new Dense(2, 4, "relu"));
    model.addLayer(new Dense(4, 1, "sigmoid"));

    
    MSEloss loss;
    model.compile(&loss);

    
    model.train(X, Y, 500);


    Matrix pred = model.predict(X);
    std::cout << "Predictions:\n";
    pred.print();
}
// g++ (Get-ChildItem -Recurse -Filter *.cpp | ForEach-Object { $_.FullName }) -o main
