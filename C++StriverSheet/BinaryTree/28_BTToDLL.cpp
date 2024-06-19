#include <iostream>
#include <vector>
#include <stack>
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

// Given a Binary Tree (Bt), convert it to a Doubly Linked List(DLL).
// The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL.
// The order of nodes in DLL must be the same as in Inorder for the given Binary Tree

// Time Complexity:O(N),   Space Complexity:O(N)
class Solution
{
public:
    TreeNode *prev = NULL, *head = NULL;
    void solve(TreeNode *root)
    {
        if (root == NULL)
            return;

        solve(root->left);
        if (prev == NULL)
        {
            head = root;
        }
        else
        {
            prev->right = root;
            root->left = prev;
        }
        prev = root;

        solve(root->right);
    }
    TreeNode *BTtoDLL(TreeNode *root)
    {
        solve(root);
        return head;
    }
};

int main()
{

    return 0;
}