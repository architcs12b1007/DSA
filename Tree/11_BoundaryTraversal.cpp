#include <iostream>
#include <vector>
using namespace std;

// Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree.

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

// Approach: 1)Print root node
// 2)Print Left part (except leaf node and root node) from top to bottom
// 3)Print all leaves nodes from left to right order
// 4)Print right part (except leaf node and root node) from bottom to top

void traverseLeft(Node *root, vector<int> &ans)
{

    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;

    ans.push_back(root->data);

    if (root->left)
    {
        traverseLeft(root->left, ans);
    }
    else if (root->right)
    {
        traverseLeft(root->right, ans);
    }
}

void traverseLeaves(Node *root, vector<int> &ans)
{

    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    traverseLeaves(root->left, ans);

    traverseLeaves(root->right, ans);
}

void traverseRight(Node *root, vector<int> &ans)
{

    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;

    if (root->right)
    {
        traverseRight(root->right, ans);
    }
    else if (root->left)
    {
        traverseRight(root->left, ans);
    }

    ans.push_back(root->data);
}

// Time:O(N), Space:O(height of Tree)
vector<int> boundary(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    ans.push_back(root->data);

    traverseLeft(root->left, ans);
    // left subtree leaves
    traverseLeaves(root->left, ans);
    // right subtree leaves
    traverseLeaves(root->right, ans);
    traverseLeft(root->right, ans);

    return ans;
}

int main()
{

    return 0;
}