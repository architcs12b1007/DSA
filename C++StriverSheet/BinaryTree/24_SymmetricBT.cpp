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

// A symmetrical binary tree is a tree that forms a mirror of itself around the center. In other words, every node in the left subtree will have a mirror image in the right subtree.

// Approach: Root node lies on the mirror line. In the next level, for a symmetric tree, the node at the root’s left should be equal to the node at the root’s right.

// Time Complexity:O(N)  Space Complexity:O(N)
bool solve(TreeNode *n1, TreeNode *n2)
{
    if (n1 == NULL && n2 == NULL)
    {
        return true;
    }
    else if ((n1 != NULL && n2 == NULL) || (n1 == NULL && n2 != NULL))
    {
        return false;
    }

    // if (n1 == NULL || n2 == NULL)
    // return n1 == n2;

    if (n1->data == n2->data)
    {
        return solve(n1->left, n2->right) && solve(n1->right, n2->left);
    }
    else
    {
        return false;
    }
}
bool isSymmetric(TreeNode *root)
{
    // Write your code here
    if (root == NULL)
        return true;

    return solve(root->left, root->right);
}
int main()
{

    return 0;
}