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

// -The sequence of nodes in the linked list should be the same as that of the PREORDER traversal of BT
// -The linked list nodes are the same binary tree nodes. You are not allowed to create extra nodes.
// -The right child of a node points to the next node of the linked list whereas the left child points to NULL.

// Approach 1:Store preorder traversal in vector and then create linkedlist in that order.Time:O(N) Space:O(N)
// Approach 2: Use recursion and Move in REVERSE PREORDER (Right LEFT ROOT), keep track of prev nodes and make right child of current node to prev node and left child to NULL. Time:O(N) Space:O(N)
// Approach 3: Use Morris Traversal, Time:O(N) Space:O(1)
class Solution
{
public:
    TreeNode *prev = NULL;
    void flattenBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return;
        flattenBinaryTree(root->right);
        flattenBinaryTree(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};

// Approach 3: Use Morris Traversal. Find inorder predecoor of a node and link to right child of a node and
// then link right part of a node to its left child and make node left part to NULL.

void flattenBinaryTree(TreeNode *root)
{
    TreeNode *curr = root;

    while (curr)
    {
        // root->left == NULL (no need to change any pointer as left points to NULL & right points next preorder element)
        if (curr->left != NULL)
        {
            TreeNode *temp = curr->left;
            while (temp->right)
            {
                temp = temp->right;
            }

            temp->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        
            curr = curr->right;
    }

}

int main()
{

    return 0;
}