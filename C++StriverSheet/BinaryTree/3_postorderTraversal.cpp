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
void postOrderTraversal(TreeNode *root, vector<int> &postorder)
{
    if (root == NULL)
        return;

    postOrderTraversal(root->left, postorder);
    postOrderTraversal(root->right, postorder);
    postorder.push_back(root->data);
}

// Iterative solution:

// Time Complexity: O(N)  Space Complexity:O(N)

vector<int> postOrderTraversal(TreeNode *root)
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

        if (curr->left)
        {
            s.push(curr->left);
        }

        if (curr->right)
        {
            s.push(curr->right);
        }
    }

    reverse(ans.begin(), ans.end()); // can also do reverse using stack

    return ans;
}

int main()
{

    return 0;
}