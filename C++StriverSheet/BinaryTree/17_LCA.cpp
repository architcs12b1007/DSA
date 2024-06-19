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

// LCA is defined between two nodes x and y as the lowest node that has both x and y as descendants (where we allow a node to be a descendant of itself.)

// We can assume x and y definitely exist in the tree

// Time Complexity:O(N) Space Complexity:O(N)
TreeNode *solve(TreeNode *root, int x, int y)
{
    if (root == NULL || root->data == x || root->data == y)
        return root;

    TreeNode *ln = solve(root->left, x, y);
    TreeNode *rn = solve(root->right, x, y);

    // 4 cases are possible

    if (ln == NULL && rn == NULL)
        return NULL;
    else if (ln != NULL && rn == NULL)
        return ln;
    else if (ln == NULL && rn != NULL)
        return rn;
    else
        return root;

    // if (left == NULL)
    // {
    //     return right;
    // }
    // else if (right == NULL)
    // {
    //     return left;
    // }
    // else
    // { // both left and right are not null, we found our result
    //     return root;
    // }
}

int lowestCommonAncestor(TreeNode *root, int x, int y)
{
    TreeNode *ans = solve(root, x, y);

    if (ans)
    {
        return ans->data;
    }
    else
    {
        return -1;
    }
}

int main()
{

    return 0;
}