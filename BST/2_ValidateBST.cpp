#include <iostream>
#include <limits.h>
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

bool solve(Node *root, int low, int high)
{
    if (root == NULL)
    {
        return true;
    }

    bool leftTree = solve(root->left, low, root->data);
    bool rightTree = solve(root->right, root->data, high);

    if (root->data >= low && root->data <= high)
    {
        return leftTree && rightTree; // can also write solve() here for leftTree & right Tree
    }
    else
    {
        return false;
    }
}

// Approach 1: Find inorder Traversal of BST & check whether it is sorted or NOT.

// Approach 2: Put range for each node so that data in that node lies in that range.

// Time:O(N), Space:O(N), where N is number fo nodes

bool validateBST(Node *root)
{
    int low = INT_MIN;
    int high = INT_MAX;

    return solve(root, low, high);
}
int main()
{

    return 0;
}
