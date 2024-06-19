#include <iostream>
#include <limits.h>
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

// Given a Binary Tree with n nodes. We have to return the size of largest subtree of bonary tree which is also a BST.

// Approach: For node, we need to check left subtree is BST and right subtree is BST and for node (data)
// should lie between maxima of left subtree and minima of right subtree

struct info
{
    int maxi;
    int mini;
    int isBST;
    int size;
};

info solve(Node *root)
{
    if (root == NULL)
    {
        info i;
        i.maxi = INT_MIN; // so that it is always true for node having left child null
        i.mini = INT_MAX; // so that it is always true for node having right child null
        i.size = 0;
        i.isBST = true;

        return i; // return {INT_MIN, INT_MAX,0,true};
    }

    info leftSubtree = solve(root->left);
    info rightSubtree = solve(root->right);

    info i;
    i.maxi = max(rightSubtree.maxi, root->data); // in case right subtree is NULL, so consider root node as well
    i.mini = min(leftSubtree.mini, root->data);  // in case left subtree is NULL, so consider root node as well

    if (leftSubtree.isBST && rightSubtree.isBST && root->data > leftSubtree.maxi && root->data < rightSubtree.mini)
    {

        i.size = 1 + leftSubtree.size + rightSubtree.size;
        i.isBST = true;

        return i;
    }

    i.size = max(leftSubtree.size, rightSubtree.size);
    i.isBST = false;
    return i;
}

// Time Complexity:O(N), Space Complexity:O(h), where h is height of Binary Tree

int largestBST(Node *root)
{

    return solve(root).size;
}

int main()
{

    return 0;
}