Let's say we have a knapsack with a maximum capacity of 10 kg and the following items:
Item 1: Value = 60, Weight = 10
Item 2: Value = 100, Weight = 20
Item 3: Value = 120, Weight = 30
The algorithm would tell us that the maximum value we can achieve is 220 by selecting items 1 and 3.
That's it! The Knapsack algorithm efficiently finds the optimal combination of items to maximize value within a weight constraint, making it useful in various real-world scenarios like resource allocation, scheduling, and financial portfolio optimization

    
#include <iostream>


using namespace std;

// Structure to represent items
struct Item {
    int value;   // Value of the item
    int weight;  // Weight of the item

    // Constructor
    Item(int value, int weight) : value(value), weight(weight) {}
};

// Comparison function to sort items by value per unit weight (value/weight ratio)
bool cmp(const Item &a, const Item &b) {
    double ratio1 = (double)a.value / a.weight;
    double ratio2 = (double)b.value / b.weight;
    return ratio1 > ratio2;
}

// Function to solve fractional knapsack problem
double fractionalKnapsack(int capacity, vector<Item> &items) {
    // Sort items by value per unit weight
    sort(items.begin(), items.end(), cmp);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (const Item &item : items) {
        // If adding the whole item doesn't exceed capacity, add it
        if (currentWeight + item.weight <= capacity) {
            totalValue += item.value;
            currentWeight += item.weight;
        } else {
            // Add fractional part of the item
            int remainingCapacity = capacity - currentWeight;
            totalValue += (double)item.value / item.weight * remainingCapacity;
            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    vector<Item> items = {
        {60, 10},  // Item 1: value = 60, weight = 10
        {100, 20}, // Item 2: value = 100, weight = 20
        {120, 30}  // Item 3: value = 120, weight = 30
    };

    int capacity = 50; // Knapsack capacity

    double maxValue = fractionalKnapsack(capacity, items);

    cout << "Maximum value in knapsack = " << maxValue << endl;

    return 0;
}
