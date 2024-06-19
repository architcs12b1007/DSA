#include <iostream>
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
// left most node gives MINIMUM
Node *minInBST(Node *root)
{
    if (root == NULL)
        return root;

    Node *temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp;
}
// right most node gives MAXIMUM
Node *maxInBST(Node *root)
{
    if (root == NULL)
        return root;

    Node *temp = root;

    while (temp->right != NULL)
    {
        temp = temp->right;
    }

    return temp;
}

// Inorder successor of a node is the next node in Inorder traversal of the BST. Inorder Successor is NULL for the last node in Inorder traversal.

// Approach 1:
// 1)If right subtree of node is not NULL, then succ lies in right subtree. Go to right subtree and return the node with minimum key value in the right subtree.

// 2)If right subtree of node is NULL, then start from the root and use search-like technique. Do the following. Travel down the tree, if a node’s data is greater than root’s data then go right side, otherwise, go to left side.
// [Travel up using the parent pointer until you see a node which is left child of its parent. The parent of such a node is the succ.] We can also use TOP-DOWN APPROACH as implemented below

// Approach 2: Use inorder Traversal also & store them in vector data structure then find next & prev element for successor and predecessor resp.

// Time:O(N), Space:O(1)
Node *inorderSuccessor(Node *root, Node *n)
{
    if (n->right)
    {
        return minInBST(n->right);
    }

    Node *temp = root;
    Node *successor = NULL;

    while (temp->data != n->data)
    {
        if (temp->data > n->data)
        {
            successor = temp; // storing parent of left child nearest to given node.
            temp = temp->left;
        }
        else if (temp->data < n->data)
        {
            temp = temp->right;
        }
    }

    return successor;
}

Node *inorderPredecessor(Node *root, Node *n)
{
    if (n->left)
    {
        return maxInBST(n->left);
    }

    Node *temp = root;
    Node *pred = NULL;

    while (temp->data != n->data)
    {
        if (temp->data > n->data)
        {
            temp = temp->left;
        }
        else
        {
            pred = temp; // storing parent of right child nearest to given node.
            temp = temp->right;
        }
    }

    return pred;
}

int main()
{

    return 0;
}
