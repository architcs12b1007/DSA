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

// Time Complexity:O(N)     Space Complexity:O(N)
vector<int> levelOrder(TreeNode *root)
{
    vector<int> ans;
    queue<TreeNode *> q;

    if (root != NULL)
    {
        q.push(root);
    }

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        ans.push_back(temp->data);

        if (temp->left)
        {
            q.push(temp->left);
        }

        if (temp->right)
        {
            q.push(temp->right);
        }
    }

    return ans;
}

int main()
{

    return 0;
}