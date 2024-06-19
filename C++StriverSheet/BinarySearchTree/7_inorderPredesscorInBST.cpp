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

TreeNode *findNode(TreeNode *root, int key)
{
    if (root == NULL)
        return root;

    if (root->data == key)
    {
        return root;
    }
    else if (root->data > key)
    {
        return findNode(root->left, key);
    }
    else
    {
        return findNode(root->right, key);
    }
}

int successor(TreeNode *root, TreeNode *keyNode, int key)
{
    TreeNode *curr = root;
    if (keyNode == NULL)
    {
        int ans = -1;

        while (root != NULL)
        {
            if (root->data > key)
            {
                ans = root->data;
                root = root->left;
            }
            else if (root->data < key)
            {
                root = root->right;
            }
        }

        return ans;
    }

    if (keyNode->right)
    { // minimum in right subtree
        TreeNode *temp = keyNode->right;

        while (temp->left != NULL)
        {
            temp = temp->left;
        }

        return temp->data;
    }

    // if no right subtree, need to find  parent having left child nearest to keyNode when traversing to keyNode

    int ans = -1;
    root = curr;
    while (root->data != key)
    {
        if (root->data > key)
        {
            ans = root->data;
            root = root->left;
        }
        else if (root->data < key)
        {
            root = root->right;
        }
    }

    return ans;
}

int predecessor(TreeNode *root, TreeNode *keyNode, int key)
{
    TreeNode *curr = root;
    if (keyNode == NULL)
    {
        int ans = -1;

        while (root != NULL)
        {
            if (root->data > key)
            {
                root = root->left;
            }
            else if (root->data < key)
            {
                ans = root->data;
                root = root->right;
            }
        }

        return ans;
    }

    if (keyNode->left)
    { // mmax in left subtree
        TreeNode *temp = keyNode->left;

        while (temp->right != NULL)
        {
            temp = temp->right;
        }

        return temp->data;
    }

    // if no left subtree, need to find parent having right child nearest to keyNode when traversing to keyNode

    int ans = -1;
    root = curr;
    while (root->data != key)
    {
        if (root->data > key)
        {
            root = root->left;
        }
        else if (root->data < key)
        {
            ans = root->data;
            root = root->right;
        }
    }

    return ans;
}

// Approach 1: Store inorder traversal and then find suc and pred. Time:O(N), Space:O(N)
// Time Complexity:O(N)  Space Complexity:O(1)
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    pair<int, int> ans{-1, -1};
    TreeNode *keyNode = findNode(root, key);
    ans.first = predecessor(root, keyNode, key);
    ans.second = successor(root, keyNode, key);
    return ans;
}
int main()
{

    return 0;
}  

  