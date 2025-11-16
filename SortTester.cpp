#include <string>
#include <vector>
#include <functional>
#include "ArrayGenerator.h"
#include "SortTester.h"


long long SortTester::testSort(std::vector<int>& arr) {
    auto start = std::chrono::high_resolution_clock::now();
    sortFunction(arr, 0, arr.size() - 1);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long usec = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    return usec;
}

SortTester::SortTester(std::function<void(std::vector<int>&, int, int)> sortFunc) {
    this->sortFunction = sortFunc;
}

long long SortTester::testRandomArray(int size) {
    std::vector<int> arr(size);
    ArrayGenerator generator;
    generator.generateRandomArray(arr, GeneratorParams{0, 10000});
    return testSort(arr);
}

long long SortTester::testHardArray(int size) {
    std::vector<int> arr(size);
    ArrayGenerator generator;
    generator.generateHardArray(arr, GeneratorParams{0, 10000});
    return testSort(arr);
}

long long SortTester::testEasyArray(int size) {
    std::vector<int> arr(size);
    ArrayGenerator generator;
    generator.generateEasyArray(arr, GeneratorParams{0, 10000});
    return testSort(arr);
}