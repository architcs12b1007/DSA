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
void inorderTraversal(Node *root, vector<int> &inorder)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}

// Approach: Store inorder of a BST in form of vector<int> and then iterate through vector ans make left pointer point to NULL ans right pointer point to next element.

// Time:O(N), Space:O(N)
Node *FlattenBSTToSortedLL(Node *root)
{
    if (root == NULL)
        return root;
    vector<int> inorder;
    inorderTraversal(root, inorder);

    int size = inorder.size();

    Node *curr = new Node(inorder[0]);
    Node* head=curr;

    for (int i = 1; i < size; i++)
    {
        Node *temp = new Node(inorder[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;

    return head;
}

int main()
{

    return 0;
}
