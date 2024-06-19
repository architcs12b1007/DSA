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

// It is integer which is greater than or equal to x.
// NOTE:X is NOT smaller than the smallest node of a BST

// Time Complexity:O(N) Space Complexity:O(1) {kind of succ}
int findCeil(BinaryTreeNode *root, int x)
{
    int ans=-1;

    while (root != NULL)
    {
        if (root->data == x)
        {
            return x;
        }
        else if (root->data > x)
        {
            ans = root->data;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    return ans;
}

int main()
{

    return 0;
}