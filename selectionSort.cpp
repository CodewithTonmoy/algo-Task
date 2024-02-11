#include <iostream>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        
        int minIndex = i;

       
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Unsorted array: ";
    printArray(arr, n);

    selectionSort(arr, n);

    std::cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
