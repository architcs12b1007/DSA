#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right, *next;
    TreeNode(int x)
    {
        data = x;
        this->left = NULL;
        this->right = NULL;
        this->next = NULL;
    }
};

// Task is to connect all adjacent nodes at the same level in the given binary tree by populating each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL. Initially, all next pointers are set to NULL.

// Time Complexity: O(N)  Space Complexity:O(N) {Use Level Order Traversal}
void connect(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *curr = q.front();
            q.pop();

            if (i != size - 1)
            {
                TreeNode *next = q.front();
                curr->next = next;
            }

            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
    }
}

// Approach: Suppose we have already populated the ‘NEXT’ pointers till level ‘L’. Now we can iterate over level ‘L’ using ‘NEXT’ pointers and populate ‘next’ pointers in level ‘L + 1’.

// Time Complexity: O(N)  Space Complexity:O(1) {Use Optimized Level Order Traversal}
void connect(TreeNode *root)
{    
    TreeNode *startNode = root;

    while (startNode)
    {
        TreeNode *ptr = startNode;
        TreeNode *prev = NULL;
        startNode = NULL;
        while (ptr != NULL)
        {

            if (ptr->left)
            {
                if (prev)
                {
                    prev->next = ptr->left;
                    prev = ptr->left;
                }
                else
                {
                    prev = ptr->left;
                }

                if (startNode == NULL)
                {
                    startNode = ptr->left;
                }
            }

            if (ptr->right)
            {
                if (prev)
                {
                    prev->next = ptr->right;
                    prev = ptr->right;
                }
                else
                {
                    prev = ptr->right;
                }
                if (startNode == NULL)
                {
                    startNode = ptr->right;
                }
            }
            ptr = ptr->next;
        }
    }
}
int main()
{

    return 0;
}