#include <iostream>
#include <vector>

using namespace std;

class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left, *right;
    BinaryTreeNode(int x)
    {
        data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

// Time Complexity: O(H),   Space Complexity:O(H)  where H is the height of the tree
// {But O(N) in case of skewed tree}
bool searchInBST(BinaryTreeNode *root, int x)
{
    if (root == NULL)
        return false;

    if (root->data == x)
    {
        return true;
    }
    else if (root->data > x)
    {
        return searchInBST(root->left, x);
    }
    else
    {
        return searchInBST(root->right, x);
    }
}

// iterative Approach:

// Time Complexity: O(H),   Space Complexity:O(1)  where H is the height of the tree
// {But O(N) in case of skewed tree}
bool searchInBST(BinaryTreeNode *root, int x)
{

    while (root != NULL)
    {
        if (root->data == x)
        {
            return true;
        }
        else if (root->data > x)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    return false;
}
int main()
{

    return 0;
}