#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// The maximum width of a binary tree is the maximum of all the level widths.
// Width for a level is defined as the maximum number of nodes between the leftmost and rightmost node of the level(including the end nodes and the null nodes between the end nodes).
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

// If NULL NODES are Calculated
// If a node has index i, its left child index will be 2*i+1 and its right child index will be 2*i+2.
// Also make sure offset the index by left child (so that each level node numbering starts from 1)
// Time Complexity:O(N)  Space Complexity:O(N)

int getMaxWidth(TreeNode *root)
{
    // Write your code here.
    int ans = 0;
    queue<pair<TreeNode *, int>> q;

    if (root != NULL)
    {
        q.push({root, 0});
    }

    while (!q.empty())
    {
        int size = q.size();

        int leftchildIndex = 0, rightchildIndex = 0;
        int offset = q.front().second;

        for (int i = 0; i < size; i++)
        {
            pair<TreeNode *, int> temp = q.front();
            q.pop();

            temp.second -= offset;
            if (i == 0)
            {
                leftchildIndex = temp.second;
            }

            if (i == size - 1)
            {
                rightchildIndex = temp.second;
            }

            if (temp.first->left)
            {
                q.push({temp.first->left, (long long)2 * temp.second + 1});
            }
            if (temp.first->right)
            {
                q.push({temp.first->right, (long long)2 * temp.second + 2});
            }
        }

        ans = max(ans, rightchildIndex - leftchildIndex + 1);
    }

    return ans;
}

// if null nodes are NOT calculated
// Time Complexity:O(N)  Space Complexity:O(N)
int getMaxWidth(TreeNode *root)
{
    // Write your code here.
    int ans = 0;
    queue<TreeNode *> q;

    if (root != NULL)
    {
        q.push(root);
    }

    while (!q.empty())
    {
        int size = q.size();
        ans = max(ans, size);

        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}