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

    solve(root->left, k, ans);
    k--;
    if (k == 0)
    {
        ans = root->data;
        return;
    }
    solve(root->right, k, ans);
}
// Approach 1: Store inorder traversal in vector and give (k-1)th index element
// Approach 2: Use recurson and travel inorder and reduce value of k till it becomes zero, store ans

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