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

//  Diameter is the length of the longest path between any 2 nodes in the tree and this path may or may not pass from the root.
// The number of edges between two nodes represents the length of the path between them

// Time Complexity:O(N)  Space Complexity:O(N)
int height(TreeNode *root, int &ans)
{
    if (root == NULL)
        return 0;

    int lh = height(root->left, ans);
    int rh = height(root->right, ans);
    ans = max(ans, lh + rh);
    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode *root)
{
    int ans = 0;
    height(root, ans);
    return ans;
}

int main()
{

    return 0;
}