#include <iostream>


int linearSearch(const int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i;  
        }
    }

    return -1;  
}

int main() {
    const int size = 5;
    int array[size] = {10, 5, 8, 2, 7};
    int target;

    std::cout << "Enter the element to search: ";
    std::cin >> target;

    int result = linearSearch(array, size, target);

    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}
