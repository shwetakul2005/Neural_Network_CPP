#include <iostream>
// #include "../layers/layer.hpp"
// #include "../layers/dense_layer.hpp"
// #include "../activations/activation.hpp"
// #include "../activations/sigmoid.hpp"
// #include "../activations/tanh.hpp"
// #include "../activations/relu.hpp"
// #include "../losses/loss.hpp"
#include "neural_network.hpp"



    void NeuralNetwork:: addLayer(Layer* layer){
        layers_.push_back(layer);
    };

    Matrix NeuralNetwork::predict(const Matrix& input){
        Matrix output = input;
        for(auto layer:layers_){
            output = layer->forward(output);
        }
        return output;
    };

    void NeuralNetwork::compile(Loss* lossFunc) {
        loss_ = lossFunc;
    };

    void NeuralNetwork::train(const Matrix& X, const Matrix& Y, int epochs){
        std::vector<Matrix> y_pred;
        for(int epoch=0; epoch<epochs; epoch++){

            // fwd pass
            Matrix y_pred = predict(X);
            
            // calculate the loss
            double loss = loss_->forward(y_pred, Y);

            // calc the gradient of the loss func
            Matrix grad_loss = loss_->backward(y_pred, Y);

            // futher calc the gradients wrt the differnt layers(activation, dense)
            Matrix grad = grad_loss;
            for(int j=layers_.size()-1; j>=0; j--){
                grad = layers_[j]->backward(grad);
            }

            // update the weights and biases
            for(auto layer:layers_){
                layer->update(0.01);
            }
            std::cout << "Epoch " << epoch + 1 << " | Loss: " << loss << std::endl;    
        }
    };

// Design notes:

// Think of this as your “high-level API”.

// Should not depend on specific layer types.

// Easy to extend to CNN or RNN models later.