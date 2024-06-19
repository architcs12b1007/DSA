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

// To find the maximum sum path in a binary tree.
// A path in a binary tree is a sequence of nodes where every adjacent pair of nodes are connected by an edge.
// A node can only appear in the sequence at most once. A path need not pass from the root.

// Approach: if a max path passing through a node: 4 cases are possible:
// Only Node; Only Node+ Max path through left child ; Only Node+ Max path through right child;
// Max path through left child + Only Node+ Max path through right child;

int solve(TreeNode *root, int &ans)
{
    if (root == NULL)
        return 0;

    int left = solve(root->left, ans);
    int right = solve(root->right, ans);

    int temp = max(max(left, right) + root->data, root->data); // 3 cases covered

    ans = max(ans, max(temp, root->data + left + right)); // 4th case covered

    return temp; // return max possible path which ends at that node (root of subtree) {3 cases are possible}
}

// Time Complexity:O(N) Space Complexity:O(N)
int maxPathSum(TreeNode *root)
{
    int ans = 0;
    solve(root, ans);
    return ans;
}

int main()
{

    return 0;
}