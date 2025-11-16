#ifndef A2_SORTTESTER_H
#define A2_SORTTESTER_H

#include <vector>
#include <functional>
#include <chrono>

class SortTester {
private:
    std::function<void(std::vector<int>&, int, int)> sortFunction;
    long long testSort(std::vector<int>& arr);

public:
    SortTester(std::function<void(std::vector<int>&, int, int)> sortFunc);
    long long testRandomArray(int size);
    long long testHardArray(int size);
    long long testEasyArray(int size);
};

#endif //A2_SORTTESTER_H
