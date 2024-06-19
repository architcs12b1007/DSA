#include <iostream>
#include <vector>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode(int x)
    {
        data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

// Return the size of the largest subtree of the binary tree which is also a BST

struct info
{
    int low;  // low denoting the minimum value of data in the left subtree
    int high; // high denoting the maximum value of data in the right subtree
    int size;
    bool isBST;
};

info solve(TreeNode *root)
{
    if (root == NULL)
    {
        info f;
        f.size = 0;
        f.isBST = true;
        f.low = INT_MAX;
        f.high = INT_MIN;
        return f;
    }

    info left = solve(root->left);
    info right = solve(root->right);
    info f;

    if (left.isBST && right.isBST && root->data > left.high && root->data < right.low)
    {

        f.size = 1 + left.size + right.size;
        f.isBST = true;
    }
    else
    {
        f.size = max(left.size, right.size);
        f.isBST = false;
    }

    f.low = min(root->data, left.low);
    f.high = max(root->data, right.high);

    return f;
}

int largestBST(TreeNode *root)
{
    return solve(root).size;
}

int main()
{

    return 0;
}