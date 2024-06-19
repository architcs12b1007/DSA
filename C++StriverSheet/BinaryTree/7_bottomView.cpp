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

// First we have to make a queue of pair which have nodes and their respective +ve and -ve indexes.(hori dis)
// Then we need a map data structure to store the h.d. and nodes data. This map will store the data in the form of sorted orders of keys(h.d.)
// Here we will follow the level order traversal.

// Time Complexity:O(N)  Space Complexity:O(N)
vector<int> getBottomView(TreeNode *root)
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

        // if (!mp.count(temp.second))
        //{
        mp[temp.second] = temp.first->data;
        //}

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