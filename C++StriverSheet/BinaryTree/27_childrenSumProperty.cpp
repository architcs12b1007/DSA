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

// Return true if all non-leaf nodes in a given binary tree have a vakue that is equal to sum of their child nodes, else return false.

// Approach 1: do level order traversal and check condition:

// Approach 2: Use recursion

// Time Complexity:O(N)  Space Complexity:O(N)
bool isParentSum(TreeNode *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return true;

    bool left = isParentSum(root->left);
    bool right = isParentSum(root->right);
    int ldata = 0, rdata = 0;
    if (root->left)
        ldata = root->left->data;
    if (root->right)
        rdata = root->right->data;

    return left && right && (root->data == ldata + rdata);
}

int main()
{

    return 0;
}