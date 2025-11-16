#include <stdio.h>
#include <chrono>
#include <vector>
#include "ArrayGenerator.h"
#include "instertionMerge.h"
#include "SortTester.h"

int main() {
    for (int i = 500; i < 100000; i += 100) {
        // SortTester tester(mergeSort);
        SortTester tester([](std::vector<int> &vec, int left, int right) {
            insertionMerge(vec, left, right, 16);
        });
        long long usec1 = tester.testRandomArray(i);
        long long usec2 = tester.testHardArray(i);
        long long usec3 = tester.testEasyArray(i);
        printf("%d,%lld,%lld,%lld\n", i, usec1, usec2, usec3);
    }

    return 0;
}