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

// Approach: Find a node such that its data lies between data of 2 given nodes

TreeNode *solve(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return NULL;
    else if (root->data >= p->data && root->data <= q->data)
    {
        return root;
    }
    else if (root->data > p->data && root->data > q->data)
    {
        return solve(root->left, p, q);
    }
    else
    {
        return solve(root->right, p, q);
    }
}

// Time Complexity: O(H) Space:O(H), where H is height of Tree {O(N) in worst case}

TreeNode *LCAinaBST(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (p->data > q->data)
    {
        solve(root, q, p);
    }
    else
        return solve(root, p, q);
}

// Can also do in iteration: Time:O(H)  Space:O(1)
TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    TreeNode *cur = root;
    while (cur != NULL)
    {
        if (cur->data > P->data && cur->data > Q->data)
        {
            cur = cur->left;
        }
        else if (cur->data < P->data && cur->data < Q->data)
        {
            cur = cur->right;
        }
        else
        {
            return cur;
        }
    }
    return NULL;
}
int main()
{

    return 0;
}