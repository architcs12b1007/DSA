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

void solve(Node *root, int &k, int &ans) // want to store state of k, so pass by reference
{
    if (root == NULL)
        return;

    solve(root->left, k, ans);
    k--;
    if (k == 0)
    {
        ans = root->data;
        return;
    }
    solve(root->right, k, ans);
}
// Approach 1: Do inordeTraversal and stops when accessing kth element in that order
// Time:O(N), Space:O(N)

// Approach 2:Use morris traversal to get inorder traversal in O(N) time and O(1) space
// (Space optimization is possible)

// kth largest== find (n-k+1) smallest element

int kthSmallest(Node *root, int k)
{
    int ans = -1;
    solve(root, k, ans);
    return ans;
}

int main()
{

    return 0;
}
