#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
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

// input: 1
//          3   ouput: 1,#,3,#,#,
// Approach: Use level order traversal. In serializing, whenever node does not have a child, we insert '#' (can choose) charachter in my string to represent NULL Node.We are using ',' as a delimeter. In deserializing, when we get '#' insert NULL and do not add push into queue.

// Time Complexity: O(N), Space Complexity:O(N)
string serializeTree(TreeNode *root)
{
    string ans = "";
    queue<TreeNode *> q;

    if (root)
    {
        q.push(root);
    }

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        if (temp)
        {
            ans += to_string(temp->data) + ",";
        }
        else
        {
            ans += "#,";
        }

        if (temp)
        { // this time we are pushing NULL values also
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    return ans;
}

TreeNode *deserializeTree(string &data)
{
    if (data.size() == 0)
        return NULL;

    stringstream s(data);
    string str;

    getline(s, str, ',');

    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();

        getline(s, str, ',');

        if (str == "#")
        {
            temp->left = NULL;
        }
        else
        {
            TreeNode *curr = new TreeNode(stoi(str));
            temp->left = curr;
            q.push(curr);
        }

        getline(s, str, ',');

        if (str == "#")
        {
            temp->right = NULL;
        }
        else
        {
            TreeNode *curr = new TreeNode(stoi(str));
            temp->right = curr;
            q.push(curr);
        }
    }

    return root;
}

int main()
{

    return 0;
}

// IN BST, we can store only inorder(preorder) traversal for serialization as we can restore BST from that traversal