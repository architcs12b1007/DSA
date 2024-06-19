#include <iostream>
#include <vector>
#include <stack>
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

// Recursive Solution
// Time Complexity:O(N)  Space Complexity:O(N)
void preOrderTraversal(TreeNode *root, vector<int> &preorder)
{
    if (root == NULL)
        return;

    preorder.push_back(root->data);

    preOrderTraversal(root->left, preorder);
    preOrderTraversal(root->right, preorder);
}

// Iterative solution:

// Time Complexity: O(N)  Space Complexity:O(N)

vector<int> preOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> s;

    if (root != NULL)
    {
        s.push(root);
    }

    TreeNode *temp = root;

    while (!s.empty())
    {
        TreeNode *curr = s.top();
        ans.push_back(curr->data);
        s.pop();

        if (curr->right)
        {
            s.push(curr->right);
        }

        if (curr->left)
        {
            s.push(curr->left);
        }
    }

    return ans;
}

int main()
{

    return 0;
}