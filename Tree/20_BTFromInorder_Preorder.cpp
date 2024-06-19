#include <iostream>
#include <vector>

using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int search(vector<int> in, int target, int low, int high)
{

    int ans = -1;

    for (int i = low; i <= high; i++)
    {
        if (in[i] == target)
            return i;
    }

    return ans;
}

Node *solve(vector<int> in, vector<int> pre, int &i, int start, int end)
{
    if (i >= pre.size() || start > end)
    {
        return NULL;
    }

    int element = pre[i++];
    Node *temp = new Node(element);
    int ind = search(in, element, start, end);
    temp->left = solve(in, pre, i, start, ind - 1);
    temp->right = solve(in, pre, i, ind + 1, end);

    return temp;
}

Node *buildTree(vector<int> in, vector<int> pre)
{
    int start = 0;
    int end = pre.size() - 1;
    int index = 0;

    solve(in, pre, index, start, end);
}

int main()
{

    return 0;
}