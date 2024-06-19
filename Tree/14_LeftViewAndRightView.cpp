#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
// Approach 1: Print first node of every level (from left to Right)
// Time Complexity:O(N), Space Complexity:O(N)
vector<int> leftView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        // process entire level at once
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *currNode = q.front();
            q.pop();
            if (i == 0) // Right view: Put condition if(i==size-1)
            {
                ans.push_back(currNode->data);
            }
            if (currNode->left)
            {
                q.push(currNode->left);
            }

            if (currNode->right)
            {
                q.push(currNode->right);
            }
        }
    }

    return ans;
}

// Approach 2: Do it using recursion (make calls from left to Right)

void preorderTraversal(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
        return;

    if (level = ans.size())
    { // u entered into new level
        ans.push_back(root->data);
    }

    preorderTraversal(root->left, ans, level + 1);
    preorderTraversal(root->right, ans, level + 1);
}

vector<int> leftView1(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    preorderTraversal(root, ans, 0);

    return ans;
}

// RIGHT VIEW

// Approach : Do it using recursion (make calls from right to Left)

void preorderTraversal1(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
        return;

    if (level = ans.size())
    { // u entered into new level
        ans.push_back(root->data);
    }

    preorderTraversal1(root->right, ans, level + 1);
    preorderTraversal1(root->left, ans, level + 1);
}

vector<int> rightView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    preorderTraversal1(root, ans, 0);

    return ans;
}
int main()
{

    return 0;
}