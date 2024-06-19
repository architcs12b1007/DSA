#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    int i; // row
    int j; // col

    Node(int data, int i, int j)
    {
        this->data = data;
        this->i = i;
        this->j = j;
    }
};

class compare
{

public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

// Approach 1: Create ans vector and store all n*k elemwnts in my ans vector. Sort the ans vector.
// Time Complexity:O(n*k log(n*k))

// Approach 2:We repeatedly merge two arrays until we are left with one final array?

// Approach 3: Consider first elements of k arrays and we need to find minimum, so we can use min heap to get min element and then insert next element of same array into heap
// Time Complexity: O(n*k log(k)), Where k is the number of arrays and n is the average number of elements in every array.  Space:O(k) +O(n*k) =O(n*k)

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    // Write your code here.
    priority_queue<Node *, vector<Node *>, compare> mini;

    vector<int> ans;

    for (int i = 0; i < k; i++)
    {
        Node *temp = new Node(kArrays[i][0], i, 0);
        mini.push(temp);
    }

    while (mini.size() > 0) // while(!mini.empty())
    {

        Node *temp = mini.top();
        mini.pop();
        ans.push_back(temp->data);

        int r = temp->i;
        int c = temp->j;
        c++;

        if (c < kArrays[r].size())
        {
            Node *temp1 = new Node(kArrays[r][c], r, c);
            mini.push(temp1);
        }
    }

    return ans;
}

int main()
{

    return 0;
}