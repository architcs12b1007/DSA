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

// Time:O(N), Space:O(N)
// Can do also iteratively as well(Time:O(N), Space:O(1))
Node *LCAInBST(Node *root, Node *p, Node *q)
{
    if (root == NULL)
        return root;

    if (root->data > p->data && root->data > q->data)
    {
        return LCAInBST(root->left, p, q);
    }
    else if (root->data < p->data && root->data < q->data)
    {
        return LCAInBST(root->right, p, q);
    }
    else
    { // (root->data > p->data && root->data < q->data) || (root->data < p->data && root->data > q->data)
        return root;
    }
}

int main()
{

    return 0;
}
