#include <iostream>


void countingSort(std::vector<int>& arr) {
    
    int maxElement = *std::max_element(arr.begin(), arr.end());

    
    std::vector<int> count(maxElement + 1, 0);

    
    for (int num : arr) {
        count[num]++;
    }

   
    for (int i = 1; i <= maxElement; ++i) {
        count[i] += count[i - 1];
    }

    
    std::vector<int> result(arr.size());
    
   
    for (int i = arr.size() - 1; i >= 0; --i) {
        result[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

   
    for (size_t i = 0; i < arr.size(); ++i) {
        arr[i] = result[i];
    }
}

int main() {
    
    std::vector<int> arr = {4, 2, 7, 1, 3, 9, 5, 8, 6};
    
    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    countingSort(arr);

    std::cout << "\nSorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}
