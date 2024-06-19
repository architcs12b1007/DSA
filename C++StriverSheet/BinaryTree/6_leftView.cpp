#include <iostream>
#include <vector>
#include <queue>
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

// The left view of a Binary Tree is a set of nodes visible when the tree is viewed from the left side.

// Approach: Do level order traversal of binary tree & print FIRST NODE ONLY at each level.(LEFT VIEW)
// Approach: Do level order traversal of binary tree & print LAST NODE ONLY at each level.(RIGHT VIEW)

// Time Complexity:O(N)        Space:O(N)
vector<int> getLeftView(TreeNode *root)
{
    vector<int> ans;
    queue<TreeNode *> q;

    if (root != NULL)
    {
        q.push(root);
    }

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {

            TreeNode *temp = q.front();
            q.pop();
            if (i == 0)
            {
                ans.push_back(temp->data);
            }

            if (temp->left)
            {
                q.push(temp->left); // for right view, insert right child first befor left child
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }

    return ans;
}

// Recursion: Left view  Time:O(N),  Space:O(H), H is height of the tree

void solve(TreeNode *root, int level, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (level = ans.size())
    {
        ans.push_back(root->data)
    }

    solve(root->left, level + 1, ans);
    solve(root->right, level + 1, ans);
}

vector<int> leftViewRecursion(TreeNode *root)
{
    vector<int> ans;
    solve(root, 0, ans) return ans;
}
int main()
{

    return 0;
}