#include "instertionMerge.h"
#include <iostream>
#include <vector>


void merge(std::vector<int> &arr, int left, int mid, int right) {
    std::vector<int> temp;
    int midIter = mid + 1;
    int leftIter = left;
    while (leftIter <= mid && midIter <= right) {
        if (arr[leftIter] <= arr[midIter]) {
            temp.push_back(arr[leftIter++]);
        } else {
            temp.push_back(arr[midIter++]);
        }
    }
    while (leftIter <= mid) {
        temp.push_back(arr[leftIter++]);
    }
    while (midIter <= right) {
        temp.push_back(arr[midIter++]);
    }
    for (int i = 0; i < temp.size(); i++) {
        arr[left + i] = temp[i];
    }
}

void insertionSort(std::vector<int> &arr, int left, int right) {
    for (int i = left; i < right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void mergeSort(std::vector<int> &arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void insertionMerge(std::vector<int> &arr, int left, int right, int insertionSortThreshold = 0) {
    if (right - left <= insertionSortThreshold) {
        insertionSort(arr, left, right + 1);
    } else {
        int mid = (left + right) / 2;
        insertionMerge(arr, left, mid, insertionSortThreshold);
        insertionMerge(arr, mid + 1, right, insertionSortThreshold);
        merge(arr, left, mid, right);
    }
}