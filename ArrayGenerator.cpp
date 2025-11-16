#include <random>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "ArrayGenerator.h"

std::vector<int> ArrayGenerator::generateRandomArray(std::vector<int> &arr, GeneratorParams params) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(params.min, params.max);
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = dis(gen);
    }
    return arr;
}
std::vector<int> ArrayGenerator::generateHardArray(std::vector<int> &arr, GeneratorParams params) {
    generateRandomArray(arr, params);
    std::sort(arr.begin(), arr.end());
    std::reverse(arr.begin(), arr.end());
    return arr;
}
std::vector<int> ArrayGenerator::generateEasyArray(std::vector<int> &arr, GeneratorParams params) {
    generateRandomArray(arr, params);
    std::sort(arr.begin(), arr.end());
    double swapPercentage = 0.05;
    int swaps = arr.size() * swapPercentage;
    for (int i = 0; i < swaps; i++) {
        int i1 = rand() % arr.size();
        int i2 = rand() % arr.size();
        std::swap(arr[i1], arr[i2]);
    }
    return arr;
}