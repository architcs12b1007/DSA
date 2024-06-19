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

TreeNode *solve(vector<int> &inorder, vector<int> &postorder, int &index, int start, int end, unordered_map<int, int> &mp)
{
    if (index < 0 || start > end)
        return NULL;

    // int pos = searchInInorder(inorder, start, end, preorder[index]);
    int pos = mp[postorder[index]];
    TreeNode *curr = new TreeNode(postorder[index--]);

    curr->right = solve(inorder, postorder, index, pos + 1, end, mp);
    curr->left = solve(inorder, postorder, index, start, pos - 1, mp);

    return curr;
}

// Time Complexity:O(N)  Space Complexity:O(N)
TreeNode *buildBinaryTree(vector<int> &inorder, vector<int> &postorder)
{
    int index = inorder.size() - 1;
    unordered_map<int, int> mp;

    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i; // store index of each inorder element
    }

    TreeNode *root = solve(inorder, postorder, index, 0, postorder.size() - 1, mp);
    return root;
}

int main()
{

    return 0;
}