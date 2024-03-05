#include <iostream>

void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {7, 3, 2, 6, 4, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    // Output: 1 2 3 4 5 6 7
    return 0;
}
