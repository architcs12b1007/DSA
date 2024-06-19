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
// A new key is always inserted at leaf by maintaining the BST property
// Time Complexity:O(h), where h=logn is height of a tree, also height of a skewed tree may become N, so time complexity may become O(N)

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (root->data > data)
    {
        root->left = insertIntoBST(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

// Time: O(H) Space:O(H), where H is height of the tree.
bool searchIntoBST(Node *root, int data)
{
    if (root == NULL)
        return false;
    if (root->data == data)
        return true;

    if (root->data > data)
    {
        return searchIntoBST(root->left, data);
    }
    else
    {
        return searchIntoBST(root->right, data);
    }
}
// Iterative approach
// Time: O(H) Space:O(1), where H is height of the tree.
bool searchIntoBST(Node *root, int data)
{
    Node *currNode = root;

    while (currNode != NULL)
    {

        if (currNode->data == data)
            return true;
        else if (currNode->data > data)
        {
            currNode = currNode->left;
        }
        else
        {
            currNode = currNode->left;
        }
    }

    return false;
}
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

// Want to delete node having:
// 1) 0 child: simply delete node and  return NULL;
// 2) 1 child: (either left or right): simply delete this node & return left or right child of deleted Node
// 3) 2 child: Find max of leftsubtree & replace it with deleted node & then delete max node of leftsubtree
// OR Find min of rightsubtree & replace it with deleted node & then delete min node of rightsubtree

// Time:O(H), O(N) in case of skewed trees
Node *deleteFromBST(Node *root, int val)
{
    if (root == NULL)
        return root;

    if (root->data == val)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left == NULL || root->right == NULL)
        {
            Node *temp;
            if (root->left)
                temp = root->left;
            else
                temp = root->right;

            delete root;

            return temp;
        }
        else
        {
            Node *maxNode = maxInBST(root->left);
            root->data = maxNode->data;
            root->left = deleteFromBST(root->left, root->data); // delete maxNode;(wrong bcoz its NOT point to NULL when delete this node)
            return root;
        }
    }
    else if (root->data > val)
    {
        root->left = deleteFromBST(root->left, val);
    }
    else
    {
        root->right = deleteFromBST(root->right, val);
    }

    return root;
}

void preorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main()
{
    Node *root = NULL;
    root = insertIntoBST(root, 10);

    root = insertIntoBST(root, 8);

    root = insertIntoBST(root, 20);

    root = insertIntoBST(root, 6);

    preorderTraversal(root);
    cout << endl;

    cout << searchIntoBST(root, 6) << endl;

    cout << searchIntoBST(root, 64) << endl;

    cout << minInBST(root)->data << endl;
    cout << maxInBST(root)->data << endl;

    return 0;
}

// Binary Search Tree:

// Binary Tree has atmost 2 children.

// Binary Search Tree is a node-based binary tree data structure which has the following properties:

// 1)The left subtree of a node contains only nodes with keys lesser than the node’s key.
// 2)The right subtree of a node contains only nodes with keys greater than the node’s key.
// 3)The left and right subtree each must also be a binary search tree.

// Inorder Traversal of BST is SORTED ORDER.
