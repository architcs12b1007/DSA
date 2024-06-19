#include <iostream>
#include <vector>

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

TreeNode *solve(vector<int> &arr, int low, int high, int &index)
{
    if (index >= arr.size())
        return NULL;

    if (arr[index] < low || arr[index] > high)
        return NULL;

    TreeNode *root = new TreeNode(arr[index++]);

    root->left = solve(arr, low, root->data, index);
    root->right = solve(arr, root->data, high, index);
    return root;
}

// Approach: Can also convert into inorder (using sorting takes O(nlogn) time)

// Time Complexity: O(N)  Space Complexity:O(N)
TreeNode *preOrderTree(vector<int> &preOrder)
{
    // Write your code here.
    int low = INT_MIN, high = INT_MAX, index = 0;
    return solve(preOrder, low, high, index);
}
int main()
{

    return 0;
}