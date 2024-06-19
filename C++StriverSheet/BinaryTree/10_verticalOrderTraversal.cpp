#include <iostream>
#include <vector>
#include <map>
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

// On the same vertical line, print from top to bottom. If two or more nodes are overlapping at the same position(here 10 and 9), then value of node added first which will be on left side.

// Time Complexity:O(NlogN)  Space Complexity:O(N)
void solve(TreeNode *root, int hd, int vd, map<int, map<int, vector<int>>> &mp)
{
    if (root == NULL)
        return;

    mp[hd][vd].push_back(root->data);

    solve(root->left, hd - 1, vd + 1, mp);
    solve(root->right, hd + 1, vd + 1, mp);
}

vector<int> verticalOrderTraversal(TreeNode *root)
{
    //    Write your code here.

    vector<int> ans;
    map<int, map<int, vector<int>>> mp;

    solve(root, 0, 0, mp);

    for (auto &a : mp)
    {
        for (auto &b : a.second)
        {
            for (auto &c : b.second)
            {
                ans.push_back(c);
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}