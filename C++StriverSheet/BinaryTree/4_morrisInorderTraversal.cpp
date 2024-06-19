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

// Approach:1)If no left subtree, visit node and move to right subtree
// 2)if left subtree exists, find predecessor of that node(so clearly right child of predecessor node point s to NULL) and made link to from right child of predecessor node to current node & move to left subtree
// 3)if left subtree exists and there have been link from right child of predecessor node to current node,
// visit the node and remove the link and then move to right subtree.

// Time Complexity:O(N) Space:O(1)
vector<int> inorderTraversal(TreeNode *root)
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
                temp->right = curr;
                curr = curr->left;
            }
            else
            {
                ans.push_back(curr->data);
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