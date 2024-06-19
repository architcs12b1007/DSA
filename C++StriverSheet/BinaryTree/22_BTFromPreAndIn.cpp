#include <iostream>
#include <vector>
#include <unordered_map>
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

int searchInInorder(vector<int> &inorder, int start, int end, int data)
{
    for (int i = start; i < end; i++)
    {
        if (inorder[i] == data)
        {
            return i;
        }
    }

    return -1;
}

TreeNode *solve(vector<int> &inorder, vector<int> &preorder, int &index, int start, int end, unordered_map<int, int> &mp)
{
    if (index >= preorder.size() || start > end)
        return NULL;

    // int pos = searchInInorder(inorder, start, end, preorder[index]);
    int pos = mp[preorder[index]];
    TreeNode *curr = new TreeNode(preorder[index++]);

    curr->left = solve(inorder, preorder, index, start, pos - 1, mp);
    curr->right = solve(inorder, preorder, index, pos + 1, end, mp);

    return curr;
}

// Time Complexity:O(N)  Space Complexity:O(N)
TreeNode *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    int index = 0;
    unordered_map<int, int> mp;

    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i; // store index of each inorder element
    }

    TreeNode *root = solve(inorder, preorder, index, 0, preorder.size() - 1, mp);
    return root;
}

int main()
{

    return 0;
}