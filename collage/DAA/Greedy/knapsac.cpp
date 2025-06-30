#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
    double profit;
    double weight;

    Item(double p, double w)
    {
        profit = p;
        weight = w;
    }
};

bool compare(Item a, Item b)
{
    return a.profit / a.weight > b.profit / b.weight;
}

double Knapsack(vector<Item> &items, double capacity)
{
    sort(items.begin(), items.end(), compare);
    double maxProfit = 0.0;
    for (auto &item : items)
    {
        if (capacity >= item.weight)
        {
            maxProfit += item.profit;
            capacity -= item.weight;
        }
        else
        {
            maxProfit += item.profit * (capacity / item.weight);
            break;
        }
    }
    return maxProfit;
}

int main()
{
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    double capacity = 50;
    cout << "Maximum Profit: " << Knapsack(items, capacity) << endl;
    return 0;
}
