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

// Write a program to print Inorder, Preorder, and Postorder traversal of the tree in a single traversal.
// Time Complexity:O(N),  Space Complexity:O(N)
void solve(TreeNode *root, vector<int> &inorder, vector<int> &preorder, vector<int> &postorder)
{
    if (root == NULL)
        return;
    preorder.push_back(root->data);
    solve(root->left, inorder, preorder, postorder);
    inorder.push_back(root->data);
    solve(root->right, inorder, preorder, postorder);
    postorder.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> inorder, preorder, postorder;
    solve(root, inorder, preorder, postorder);

    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);
    return ans;
}

int main()
{

    return 0;
}