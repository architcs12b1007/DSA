#include <iostream>
#include <vector>
using namespace std;

// A Balanced BST is a BST in which height of two subtrees of every node differs no more than 1.
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

void inorderTraversal(Node *root, vector<int> &inorder)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}

Node *inorderToBST(vector<int> &v, int start, int end) // large data passed by reference (to avoid TLE)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = start + (end - start) / 2;

    Node *temp = new Node(v[mid]);
    temp->left = inorderToBST(v, start, mid - 1);
    temp->right = inorderToBST(v, mid + 1, end);

    return temp;
}

// Store inorder traversal in a vector<int> and then we need to make balanced BST from sorted array.
// Find mid element of array & create node & left subtree belongs to left subarray and right subtree belongs to right subarray.

// Time Complexity:O(N), Space Complexity:O(N)
Node *balancedBST(Node *root)
{
    vector<int> inorder;
    inorderTraversal(root, inorder);
    int size = inorder.size();

    Node *head = inorderToBST(inorder, 0, size - 1);
}

int main()
{

    return 0;
}
