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

// Maximum Depth is the count of nodes of the longest path from the root node to the leaf node.

// Can also do by level order traversal

// Use postorder Traversal and use this logic: 1+ max(leftsubtree, rightsubtree)
// Time Complexity:O(N) Space Complecity:O(N)
int heightOfBinaryTree(TreeNode *root)
{
    // Write your code here.
    if (root == NULL)
        return 0;

    return max(heightOfBinaryTree(root->left), heightOfBinaryTree(root->right)) + 1;
}
int main()
{

    return 0;
}