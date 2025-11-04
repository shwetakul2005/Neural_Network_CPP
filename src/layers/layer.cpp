#include <iostream>
#include "layer.hpp"
#include "../core/matrix.hpp"

// Core responsibilities:
void Layer::set_train(bool mode) {
    train_mode_ = mode;         // lets a layer set the mode to train/eval
}
bool Layer::is_training() const{
    return train_mode_;         // allows derived layers (like Dropout) to check the current mode.
}

// int main(){
//     return 0;
// }

// Each layer defines its own:
// ->forward()
// ->backward()
// ->initialize()
// ->Store its weights, biases, gradients, and activation.