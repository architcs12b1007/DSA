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

// return the zigzag level order traversal of Binary Tree. (i.e., from left to right, then right to left for the next level and alternate between).

// Approach:We also need to keep the left to right bool variable that keeps check of the current level we are in.(To check where store data in each level in normal way or in reverse way)

// Time Complexity:O(N)  Space Complexity:O(N)

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    queue<TreeNode *> q;

    if (root != NULL)
    {
        q.push(root);
    }

    bool leftToRight = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp(size);
        int index;

        for (int i = 0; i < size; i++)
        {
            TreeNode *frontNode = q.front();
            q.pop();
            if (leftToRight)
            {
                index = i;
            }
            else
            {
                index = size - 1 - i;
            }
            temp[index] = frontNode->data;
            if (frontNode->left)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
        ans.push_back(temp);
        leftToRight = !leftToRight;
    }

    return ans;
}
int main()
{

    return 0;
}