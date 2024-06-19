// Given a binary search tree which is also a complete binary tree. The problem is to convert the given BST into a Min Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node.This condition is applied to all the nodes, in the resultant converted Min Heap.

#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// 2 conditions: 1)Minheap (N < left & N < right part)2)Given conditions (Left part < Right Part)
// (N<L<R) (so need values in sorted order)

// Approach: Since it is CBT, so its structure won't change after converting into Min Heap (ony value changes
// Store Inorder traversal in vector from BST & then do preorder traversal in sorted inorder vector and store answer in BST.
// Wht preorder??? (N<L<R) {inorder vector is in sorted order, so it satify the given condition}

void inorderTraversal(Node *root, vector<int> &inorder)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}

void fillPreOrder(Node *root, vector<int> inorder, int &i)
{
    if (root == NULL)
        return;

    root->data = inorder[i++];
    fillPreOrder(root->left, inorder, i);
    fillPreOrder(root->right, inorder, i);
}

// Time Complecity:O(N)   Space Complexity:O(N)

void convertToMinHeap(Node *root)
{
    if (root == NULL)
        return;

    vector<int> inorder;

    inorderTraversal(root, inorder);
    int index = 0;
    fillPreOrder(root, inorder, index);
}

int main()
{
    return 0;
}