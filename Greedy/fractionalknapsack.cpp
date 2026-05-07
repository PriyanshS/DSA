#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Item {
    char id; // Using char for A, B, C, D
    double weight, profit, ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

double getFractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);

    double totalProfit = 0.0;
    double currentWeight = 0;

    cout << "Items selected (Greedy Order):" << endl;
    for (const auto& item : items) {
        if (currentWeight + item.weight <= W) {
            currentWeight += item.weight;
            totalProfit += item.profit;
            cout << "Item " << item.id << ": 100% (Weight: " << item.weight << ")" << endl;
        } else {
            double remaining = W - currentWeight;
            totalProfit += item.profit * (remaining / item.weight);
            cout << "Item " << item.id << ": " << (remaining / item.weight) * 100 
                 << "% (Weight: " << remaining << ")" << endl;
            break;
        }
    }
    return totalProfit;
}

int main() {
    // Practice Question Data 
    int W = 60; 
    vector<Item> items = {
        {'A', 40, 280, 280.0/40}, // Ratio: 7.0
        {'B', 10, 100, 100.0/10}, // Ratio: 10.0
        {'C', 20, 120, 120.0/20}, // Ratio: 6.0
        {'D', 24, 120, 120.0/24}  // Ratio: 5.0
    };

    cout << fixed << setprecision(2);
    double maxProfit = getFractionalKnapsack(W, items);
    cout << "\n----------------------------" << endl;
    cout << "Total Maximum Profit: " << maxProfit << endl;
    return 0;
}