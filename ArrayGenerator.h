#ifndef A2_ARRAYGENERATOR_H
#define A2_ARRAYGENERATOR_H

#include <vector>

struct GeneratorParams {
    int min;
    int max;
};

class ArrayGenerator {
public:
    std::vector<int> generateRandomArray(std::vector<int> &arr, GeneratorParams params);
    std::vector<int> generateHardArray(std::vector<int> &arr, GeneratorParams params);
    std::vector<int> generateEasyArray(std::vector<int> &arr, GeneratorParams params);
};

#endif //A2_ARRAYGENERATOR_H
