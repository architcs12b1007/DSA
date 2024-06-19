#include <iostream>
#include <queue>

using namespace std;

void heapify(vector<int> &arr, int index, int size)
{

    int largest = index;

    int left = 2 * index + 1, right = 2 * index + 2; // 0-indexing array

    if (left < size && arr[largest] < arr[left]) // (1-based indexing (left<=size))
        largest = left;

    if (right < size && arr[largest] < arr[right])
        largest = right;

    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        heapify(arr, largest, size);
    }
}

// Approach: create ans vector of size (m+n) & push elements of a & b into it.
// then apply heapfy algo on this.

// Time Complexity:O(m+n); Space Complexity:O(m+n)

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{

    vector<int> ans;

    for (auto i : a)
    {
        ans.push_back(i);
    }

    for (auto i : b)
    {
        ans.push_back(i);
    }

    int size = ans.size();

    // build heap for 0-indexed array (n/2-1 to 0); 1 based indexing (n/2 to 1)

    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(ans, i, size);
    }
    return ans;
}

int main()
{
    return 0;
}