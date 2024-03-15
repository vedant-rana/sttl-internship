#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int value;
    int weight;

    Item(int value, int weight) : value(value), weight(weight) {}
};

bool compareItems(const Item &item1, const Item &item2)
{
    double ratio1 = static_cast<double>(item1.value) / item1.weight;
    double ratio2 = static_cast<double>(item2.value) / item2.weight;
    return ratio1 > ratio2;
}

double fractionalKnapsack(int capacity, const vector<Item> &items)
{

    vector<Item> sortedItems = items;
    sort(sortedItems.begin(), sortedItems.end(), compareItems);

    double maxTotalValue = 0.0;
    int currentWeight = 0;

    for (const Item &item : sortedItems)
    {
        if (currentWeight + item.weight <= capacity)
        {

            currentWeight += item.weight;
            maxTotalValue += item.value;
        }
        else
        {

            double remainingCapacity = capacity - currentWeight;
            maxTotalValue += (remainingCapacity / item.weight) * item.value;
            break;
        }
    }

    return maxTotalValue;
}

int main()
{

    int capacity = 50;
    vector<Item> items = {
        {60, 10},
        {100, 20},
        {120, 30}};

    double result = fractionalKnapsack(capacity, items);

    cout << "Maximum value in the knapsack: " << result << endl;

    return 0;
}
