#include <iostream>
#include <vector>
#include <string>
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

// Time Complexity:O(N)
// Space Complexity:O(N)

void solve(TreeNode *root, string path, vector<string> &ans)
{
    if (root == NULL)
        return;

    path += to_string(root->data) + " ";

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(path.substr(0, path.size() - 1)); // to remove last space
        return;
    }

    solve(root->left, path, ans);

    solve(root->right, path, ans);
}
vector<string> allRootToLeaf(TreeNode *root)
{
    // Write your code here.
    vector<string> ans;
    string path;
    solve(root, path, ans);

    return ans;
}

int main()
{

    return 0;
}