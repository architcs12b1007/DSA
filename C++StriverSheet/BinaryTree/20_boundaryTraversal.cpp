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

// Anti-Clockwise Boundary traversal of a binary tree.

// Approach:Part 1: Left Boundary of the tree (excluding the leaf nodes).
// Part 2: All the leaf nodes travelled in the left to right direction.
// Part 3: Right Boundary of the tree (excluding the leaf nodes), traversed in the reverse direction.

void leftBoundary(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (root->left)
    {
        ans.push_back(root->data);
        leftBoundary(root->left, ans);
    }
    else if (root->right)
    {
        ans.push_back(root->data);
        leftBoundary(root->right, ans);
    }
}
void leavesOfBT(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
    }
    leavesOfBT(root->left, ans);
    leavesOfBT(root->right, ans);
}

void rightBoundary(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (root->right)
    {
        rightBoundary(root->right, ans);
        ans.push_back(root->data);
    }
    else if (root->left)
    {
        rightBoundary(root->left, ans);
        ans.push_back(root->data);
    }
}

// Time Complexity:O(N)  Space Complexity:O(N)
vector<int> traverseBoundary(TreeNode *root)
{
    // Write your code here.

    vector<int> ans;

    if (root == NULL)
        return ans;

    ans.push_back(root->data);

    leftBoundary(root->left, ans);
    leavesOfBT(root->left, ans);
    leavesOfBT(root->right, ans);
    rightBoundary(root->right, ans);

    return ans;
}

int main()
{

    return 0;
}