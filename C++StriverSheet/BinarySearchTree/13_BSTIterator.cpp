#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x)
    {
        val = x;
        this->left = NULL;
        this->right = NULL;
    }
};

// BSTIterator class that represents an iterator over the INORDER-TRAVERSAL of a binary search tree (BST):

// -BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.

// -boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.

// -int next() Moves the pointer to the right, then returns the number at the pointer.

// You may assume that next() calls will always be valid.

// Approach1: Store inorder traversal in vector and just travese vector from 0 to its size-1

// Approach2 : Just do inorder traversal iteratively. We can prepare a stack in which we store the next smallest element on its top. We update the stack on demand to maintain the next smallest element on its top.

// Time Complexity:O(N)  Space Complexity:O(N)
class BSTIterator
{
public:
    stack<TreeNode *> s;

    BSTIterator(TreeNode *root)
    {
        if (root)
        {
            s.push(root);
            while (root->left)
            {
                s.push(root->left);
                root = root->left;
            }
        }
    }

    int next()
    {
        TreeNode *temp = s.top();
        s.pop();

        if (temp->right)
        {
            s.push(temp->right);
            TreeNode *curr = temp->right;

            while (curr->left)
            {
                s.push(curr->left);
                curr = curr->left;
            }
        }

        return temp->val;
    }

    bool hasNext()
    {
        if (s.empty())
            return false;
        else
            return true;
    }
};

int main()
{

    return 0;
}