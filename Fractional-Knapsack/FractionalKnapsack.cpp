#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value, weight;
};

// Comparison function to sort items based on value/weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    int currWeight = 0;

    for (const auto& item : items) {
        if (currWeight + item.weight <= W) {
            currWeight += item.weight;
            totalValue += item.value;
        } else {
            int remain = W - currWeight;
            totalValue += item.value * ((double)remain / item.weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, W;

    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter value and weight for each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    cout << "Enter the capacity of knapsack: ";
    cin >> W;

    double max_val = fractionalKnapsack(W, items);

    cout << "Maximum value in Knapsack = " << max_val << endl;

    return 0;
}
