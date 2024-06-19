#include <iostream>
#include <vector>

using namespace std;

// root = [2147483647] {2^31-1}   output: TRUE

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

bool solve(BinaryTreeNode *root, long long low, long high)
{
    if (root == NULL)
        return true;

    if (root->data > low && root->data < high)
    {
        return solve(root->left, low, root->data) && solve(root->right, root->data, high);
    }
    else
    {
        return false;
    }
}

// Time Complexity:O(N)  Space Complexity:O(N)
bool validateBST(BinaryTreeNode *root)
{
    // Write your code here
    long long low = LONG_MIN;
    long long high = LONG_MAX;

    return solve(root, low, high);
}

int main()
{

    return 0;
}