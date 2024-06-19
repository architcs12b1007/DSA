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

// Greatest value of a node which is samller than or equal to x.
// NOTE:X is NOT smaller than the smallest node of a BST

// Time Complexity:O(N) Space Complexity:O(1) {kind of pred}
int floorInBST(TreeNode *root, int X)
{
    int ans = -1;

    while (root != NULL)
    {
        if (root->data == X)
        {
            return X;
        }
        else if (root->data > X)
        {
            root = root->left;
        }
        else
        {
            ans = root->data;
            root = root->right;
        }
    }

    return ans;
}

int main()
{

    return 0;
}