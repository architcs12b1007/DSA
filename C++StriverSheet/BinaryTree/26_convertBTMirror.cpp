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

// Given a Binary Tree, convert it into its mirror.

// Time Complexity:O(N)  Space:O(N)
void mirror(TreeNode *node)
{
    if (node == NULL)
        return;

    mirror(node->left);
    mirror(node->right);

    // swaaping right & left pointer after postorder traversal from a node
    TreeNode *temp = node->right;
    node->right = node->left;
    node->left = temp;
}

int main()
{

    return 0;
}