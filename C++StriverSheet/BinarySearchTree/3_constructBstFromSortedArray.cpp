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

// Convert it to a height-balanced binary search tree and elements in the array are given in sorted array (strictly increasing)

// Approach: We can think of making the middle element of the array root node, this will ensure that both left and right subtree have equal elements thus maintaining the balance of the tree.

TreeNode *solve(vector<int> &arr, int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start) + (end - start) / 2;
    TreeNode *root = new TreeNode(arr[mid]);

    root->left = solve(arr, start, mid - 1);
    root->right = solve(arr, mid + 1, end);
    return root;
}

// Time Complexity: O(N)  Space Complexity:O(Log N) {Balanced Tree}
TreeNode *sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    return solve(arr, 0, n - 1);
}

int main()
{

    return 0;
}