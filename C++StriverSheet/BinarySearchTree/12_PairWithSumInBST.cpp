#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left, *right;
    BinaryTreeNode(int x)
    {
        data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

// Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

// Approach 1: Store inorder traversal in vector and then find pair in vector. Time:O(N)  Space:O(N)
// Approach 2: do level order traversal and use hashmap
// Approach 3: Store inorder traversal and then do 2 pointer approach

// Time Complexity:O(N)  Space Complexity:O(N)
bool pairSumBst(BinaryTreeNode *root, int k)
{
    unordered_map<int, int> mp;

    queue<BinaryTreeNode *> q;

    if (root)
    {
        q.push(root);
    }

    while (!q.empty())
    {
        BinaryTreeNode *curr = q.front();
        q.pop();

        if (mp.count(k - curr->data))
        {
            return true;
        }

        mp[curr->data] = 1;

        if (curr->left)
        {
            q.push(curr->left);
        }

        if (curr->right)
        {
            q.push(curr->right);
        }
    }
    return false;
}

int main()
{

    return 0;
}