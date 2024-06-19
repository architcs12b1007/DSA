#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
// Note: Unlike 0/1 knapsack, you are allowed to break the item.

// Input: N = 3, W = 50,

// values[] = {60,100,120}
// weight[] = {10,20,30}
// Output:
// 240.00

struct Item
{
    int value;
    int weight;
};

// Time: O(N logN)  Space:O(N)
double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    double ans;
    vector<pair<double, int>> valuePerUnit;

    for (int i = 0; i < n; i++)
    { // need to find values per unit for all items
        valuePerUnit.push_back({(double)arr[i].value / (double)arr[i].weight, i});
    }

    sort(valuePerUnit.begin(), valuePerUnit.end(), greater<pair<double, int>>());

    for (int i = 0; i < n; i++)
    {
        int index = valuePerUnit[i].second;
        if (W >= arr[index].weight)
        {
            ans += arr[index].value;
            W -= arr[index].weight;
        }
        else
        {
            ans += ((double)W * valuePerUnit[i].first);
            break;
        }
    }

    return ans;
}
int main()
{

    return 0;
}