#include<iostream>
#include <random>
#include "matrix.hpp"

// Random number in range [min, max]
double rand_uniform(double min, double max){
    static std::random_device rd;         // Seed (non-deterministic)
    static std::mt19937 gen(rd());        // Mersenne Twister engine
    std::uniform_real_distribution<> dist(min, max);  // Uniform range
    return dist(gen);
};

// Gaussian noise (for weight init)
double rand_normal(double mean, double stddev){
    
};

// Ensures reproducible results
void set_seed(unsigned int seed){

};

// Creates a matrix of random values
Matrix random_matrix(int rows, int cols, double min, double max){
    if (rows == 0 || cols == 0) {
        std::cout<<"Matrix is empty."<<"\n";
        return Matrix();  // return empty
    }
    std::vector<std::vector<double>> data_new(rows, std::vector<double>(cols));
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            data_new[i][j] = rand_uniform(min, max);
        }
    }
    return Matrix(data_new);
};