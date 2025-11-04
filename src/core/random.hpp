#pragma once
#include<iostream>
#include "matrix.hpp"

double rand_uniform(double min, double max);
double rand_normal(double mean, double stddev);
void set_seed(unsigned int seed);
Matrix random_matrix(int rows, int cols, double min, double max);