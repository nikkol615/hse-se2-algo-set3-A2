#include <iostream>
#include <vector>
#include <algorithm>

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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    insertionMerge(arr, 0, n - 1, 16);
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}