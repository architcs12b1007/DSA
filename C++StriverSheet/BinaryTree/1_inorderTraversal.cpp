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
void inOrderTraversal(TreeNode *root, vector<int> &inorder)
{
    if (root == NULL)
        return;

    inOrderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inOrderTraversal(root->right, inorder);
}

// Iterative solution:

// Time Complexity: O(N)  Space Complexity:O(N)
vector<int> inOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> s;

    TreeNode *temp = root;
    while (true)
    {
        if (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        else
        {
            if (s.empty())
                break;

            TreeNode *curr = s.top();
            s.pop();
            ans.push_back(curr->data);
            if (curr->right) // no need for this line
                temp = curr->right;
        }
    }
    return ans;
}

int main()
{

    return 0;
}