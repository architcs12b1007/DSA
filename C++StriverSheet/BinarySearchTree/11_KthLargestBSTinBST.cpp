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

void solve(TreeNode *root, int &k, int &ans)
{
    if (root == NULL)
        return;

    solve(root->right, k, ans);
    k--;
    if (k == 0)
    {
        ans = root->data;
        return;
    }
    solve(root->left, k, ans);
}
// Approach 1: Store inorder traversal in vector and give kth largest i.e. (n-k-1)th index element
// Approach 2: Use recurson and travel reverse inorder (reverse order )and decrease k till it becomes 0, store ans

int kthSmallest(TreeNode *root, int k)
{
    //  Write the code here.
    int ans = -1;
    solve(root, k, ans);

    return ans;
}

int main()
{

    return 0;
}