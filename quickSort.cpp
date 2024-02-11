#include <iostream>
#include <vector>


int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}


void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        
        int pivotIndex = partition(arr, low, high);

        
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    
    std::vector<int> arr = {12, 4, 5, 6, 7, 3, 1, 15};
    int n = arr.size();

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

   
    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
