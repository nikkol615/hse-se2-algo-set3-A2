#ifndef A2_INSTERTIONMERGE_H
#define A2_INSTERTIONMERGE_H

#include <vector>

void merge(std::vector<int> &arr, int left, int mid, int right);
void insertionSort(std::vector<int> &arr, int left, int right);
void mergeSort(std::vector<int> &arr, int left, int right);
void insertionMerge(std::vector<int> &arr, int left, int right, int insertionSortThreshold);

#endif //A2_INSTERTIONMERGE_H
