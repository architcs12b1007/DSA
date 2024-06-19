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

//  The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

// Time Complexity:O(N)  Space Complexity:O(N)
vector<int> getTopView(TreeNode *root)
{
    vector<int> ans;
    map<int, int> mp; // store hd and correponding node data
    queue<pair<TreeNode *, int>> q;

    if (root != NULL)
    {
        q.push({root, 0}); // make_pair()
    }

    while (!q.empty())
    {
        pair<TreeNode *, int> temp = q.front();
        q.pop();

        if (!mp.count(temp.second))
        {
            mp[temp.second] = temp.first->data;
        }

        if (temp.first->left)
        {
            q.push({temp.first->left, temp.second - 1});
        }
        if (temp.first->right)
        {
            q.push({temp.first->right, temp.second + 1});
        }
    }
    // map is in sorted order
    for (auto &a : mp)
    {
        ans.push_back(a.second);
    }

    return ans;
}

int main()
{

    return 0;
}