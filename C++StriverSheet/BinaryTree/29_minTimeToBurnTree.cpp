#include <iostream>
#include <vector>
#include <map>
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

// Binary Tree have N unique nodes and a start node from where the tree will start to burn. Need to print time (in minutes)it will take to burn the whole tree.
// It is given that it takes 1 minute for the fire to travel from the burning node to its adjacent node and burn down the adjacent node.

// Approach:- Need to keep track of parents node (so create map). {use level order traversal}
// -Need to find start(target) node
// -burn the tree in min time (use bfs) {so, need visited and queue data structure}

TreeNode *createParentMapping(TreeNode *root, int start, map<TreeNode *, TreeNode *> &nodeToParent)
{
    queue<TreeNode *> q;
    TreeNode *ans = NULL;
    if (root)
    {
        q.push(root);
        nodeToParent[root] = NULL;
    }

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->data == start)
            {
                ans = temp;
            }

            if (temp->left)
            {
                q.push(temp->left);
                nodeToParent[temp->left] = temp;
            }

            if (temp->right)
            {
                q.push(temp->right);
                nodeToParent[temp->right] = temp;
            }
        }
    }

    return ans;
}

int burnTree(TreeNode *start, map<TreeNode *, TreeNode *> &nodeToParent)
{
    map<TreeNode *, bool> visited;
    queue<TreeNode *> q;
    int ans = 0;

    if (start)
    {
        q.push(start);
        visited[start] = 1;
    }

    while (!q.empty())
    {
        int size = q.size();
        bool flag = 0;
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();

            if (temp->left && !visited[temp->left])
            {
                q.push(temp->left);
                visited[temp->left] = 1;
                flag = 1;
            }
            if (temp->right && !visited[temp->right])
            {
                q.push(temp->right);
                visited[temp->right] = 1;
                flag = 1;
            }
            if (nodeToParent[temp] && !visited[nodeToParent[temp]])
            {
                q.push(nodeToParent[temp]);
                visited[nodeToParent[temp]] = 1;
                flag = 1;
            }
        }

        if (flag)
        {
            ans++; // increment only when something is added to queue
        }
    }

    return ans;
}

// Time:o(N)  Space:O(N)
int timeToBurnTree(TreeNode *root, int start)
{
    int ans = 0;
    map<TreeNode *, TreeNode *> nodeToParent;
    TreeNode *targetNode = createParentMapping(root, start, nodeToParent);
    ans = burnTree(targetNode, nodeToParent);
    return ans;
}

int main()
{

    return 0;
}