#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// 2 check are required: 1)Max heap property 2)Complete binary tree

// Approach: Find index of left and right child of node and check whether it is greater than total no of nodes

bool isCBT(Node *node, int index, int totalNodes)
{

    if (node == NULL)
        return true;

    if (index > totalNodes)
        return false;
    else
    {
        bool left = isCBT(node->left, 2 * index, totalNodes); // 1-indexing
        bool right = isCBT(node->left, 2 * index + 1, totalNodes);
        return left && right;
    }
}

// Complete tree property is satisfied. 3 cases occurs: 2 child, only left child, leaf node
bool isMaxHeapProperty(Node *node)
{

    if ((node == NULL) || (node->left == NULL && node->right == NULL))
        return true;
    else if (node->right == NULL)
    { // node->left &&
        return node->data > node->left->data;
    }
    else
    {
        return (node->data > node->left->data) && (node->data > node->right->data) && isMaxHeapProperty(node->left) && isMaxHeapProperty(node->right);
    }
}

int totalNodes(Node *node)
{

    if (node == NULL)
        return 0;

    int left = totalNodes(node->left);
    int right = totalNodes(node->right);

    return 1 + left + right;
}
// Time Complexity: O(N); Space Complexity:O(h) (h is height of tree, in sparsed tree h can be n)

// Used 1-indexing
bool isHeap(Node *node)
{

    if (isCBT(node, 1, totalNodes(node)) && isMaxHeapProperty(node))
        return true;
    else
        return false;
}

int main()
{
    return 0;
}