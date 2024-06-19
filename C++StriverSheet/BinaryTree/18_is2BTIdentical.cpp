

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

// Time:O(N) Space:O(N)  {Use PreOrder}
bool identicalTrees(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    if (root1 == NULL && root2 == NULL)
        return true;

    if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
        return false;

    if (root1->data == root2->data)
    {
        return identicalTrees(root1->left, root2->left) && identicalTrees(root1->right, root2->right);
    }
    else
    {
        return false;
    }
}
int main()
{

    return 0;
}