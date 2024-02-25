#include <iostream>
#include <map>

using namespace std;

void countMoney(double amount) {
    // Define the denominations and their values
    map<string, double> denominations = {
        {"$100", 100.0},
        {"$50", 50.0},
        {"$20", 20.0},
        {"$10", 10.0},
        {"$5", 5.0},
        {"$1", 1.0},
        {"Quarter", 0.25},
        {"Dime", 0.10},
        {"Nickel", 0.05},
        {"Penny", 0.01}
    };

    // Map to store count of each denomination
    map<string, int> count;

    // Iterate through each denomination
    for (auto it = denominations.begin(); it != denominations.end(); ++it) {
        // Count how many of this denomination fit into the remaining amount
        int num = amount / it->second;
        // Update the remaining amount
        amount -= num * it->second;
        // Store the count of this denomination
        count[it->first] = num;
    }

    // Output the count of each denomination
    for (auto it = count.begin(); it != count.end(); ++it) {
        if (it->second > 0) {
            cout << it->second << " " << it->first << endl;
        }
    }
}

int main() {
    double amount;
    cout << "Enter the total amount of money: ";
    cin >> amount;
    countMoney(amount);
    return 0;
}
