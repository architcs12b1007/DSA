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

// Time Complexity:O(N) Space:O(1)
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    TreeNode *curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL) // if no left subtree, visit node and move to right subtree
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            TreeNode *temp = curr->left;

            while (temp->right != NULL && temp->right != curr)
            {
                temp = temp->right;
            }

            if (temp->right == NULL)
            {
                ans.push_back(curr->data);
                temp->right = curr;
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
                temp->right = NULL;
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}