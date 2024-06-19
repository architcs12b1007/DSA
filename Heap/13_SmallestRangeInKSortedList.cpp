#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

// K list and each list has size has n. Each list is in non-decreasing order.
// Need to find minimum length of a range such that atleast one elemnt of each list must be included in that range.
// input: [2 4 5], [5 6 7]   ouput:1 {[5,5] length is 1}
// input: [1 1], [9 12], [4 9]  Output:9 [1,9]

// Approach 1: Take pointer array of size k that initilally store the index of each list and at the same time, we have maxi and mini variable that stores min and max value for first index of k lists.So, got the range [mini,maxi]. {Also store corresponfing listindex as well for maxi and mini}
// Now, to decrease range, either we can increase mini or decrease maxi. But decrease maxi is not possible as 0 is the lowest index & list is sorted in ascending order. so we try to increase mini.
// Now increase mini list index by 1 in pointer array and again find new mini & maxi for k lists at their index in pointer array. If difference in new range[mini, maxi] is smaller than previous, update your answer.
// Repeat this until any one of this lists gets exhausted.
// Time Complexity:O((N*K)*K) Space Complexity:O(K) (We have to do k comparision for N*K elements)

// Approach 2: Use same logic as above but use priority_queue to find min and max elements of k size.This operation happens in O(logn) time.
// Time Complexity:O((N*K)*log(K)) Space Complexity:O(K)

class Node
{
public:
    int data;
    int row;     // shows list no
    int nextCol; // shows list next element

    Node(int data, int row, int nextCol)
    {
        this->data = data;
        this->row = row;
        this->nextCol = nextCol;
    }
};

class compare
{
public:
    bool operator()(Node a, Node b)
    {
        return a.data > b.data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n)
{
    priority_queue<Node, vector<Node>, compare> mini;
    int maxi = INT_MIN;

    for (int i = 0; i < k; i++)
    {
        Node temp(a[i][0], i, 1);
        mini.push(temp);

        if (maxi < a[i][0])
        {
            maxi = a[i][0]; // maxi=max(maxi,a[i][0])
        }
    }

    int range = maxi - mini.top().data + 1;

    while (1)
    {
        Node top = mini.top();
        mini.pop();
        int row = top.row;
        int nextCol = top.nextCol;

        if (nextCol < n)
        {
            Node temp(a[row][nextCol], row, nextCol + 1);
            mini.push(temp);
        }
        else
        {
            break;
        }

        if (maxi < a[row][nextCol])
        {
            maxi = a[row][nextCol]; // maxi=max(maxi,a[row][nextCol])
        }

        if (range > maxi - mini.top().data + 1)
            range = maxi - mini.top().data + 1; // range= min(range, mini.top().data + 1)
    }

    return range;
}

int main()
{

    return 0;
}