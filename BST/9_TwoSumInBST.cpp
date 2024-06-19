#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// To find whether exists a pair of nodes whose sum is equal to target

// Approach: Store inorder traversal of BST in vector and then use 2 pointer approach whether target exists or NOT

// Inorder Traversal in BST is in sorted order.

// Time:O(N), Space:O(N)

void inorderTraversal(Node *root, vector<int> &inorder)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}
bool TwoSumInBST(Node *root, int target)
{
    vector<int> inorder;

    inorderTraversal(root, inorder);

    int start = 0;
    int end = inorder.size() - 1;

    while (start < end)
    {
        int sum = inorder[start] + inorder[end];
        if (sum == target)
        {
            return true;
        }
        else if (sum > target)
        {
            end--;
        }
        else
        {
            start++;
        }
    }

    return false;
}
int main()
{

    return 0;
}
