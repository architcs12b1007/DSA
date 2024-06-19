#include <iostream>
#include <vector>

using namespace std;

// A binary tree is balanced if, for all nodes in the tree, the difference between left and right subtree height is not more than 1.

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

// Time Complexity:O(N)  SpaceComplexity:O(N)
int heightBT(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int lh = heightBT(root->left);
    if (lh == -1)
        return -1;
    int rh = heightBT(root->right);
    if (rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
    {
        return -1;
    }

    return 1 + max(lh, rh);
}

bool isBalancedBT(TreeNode *root)
{
    // Write your code here.
    return heightBT(root) != -1;
}

int main()
{

    return 0;
}