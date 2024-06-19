#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *solve(vector<int> &preorder, int low, int high, int &i)
{
    if (i >= preorder.size())
    {
        return NULL;
    }
    if (preorder[i] < low || preorder[i] > high)
    {
        return NULL;
    }

    Node *temp = new Node(preorder[i++]);

    temp->left = solve(preorder, low, temp->data, i);

    temp->right = solve(preorder, temp->data, high, i);

    return temp;
}

// Approach 1:We can do normal insertion in BST and process each element at a time like we did in insertion implementation of a BST. Time: O(N2)

// Approach 2:Given Preoder, we can find inorder by sorting it. It is easy to generate BST from inorder and preorder as we did in Binary Trees. Time:O(NlogN)

// Approach 3:Consider initial range as {INT_MIN,INT_MAX} and insert elements where given elements lies in that range (using same approach we used in Validating BST)

// We can optimise it further as well as there is no need to pass low, we can do it without it as well, just remove low variable.

Node *preorderToBST(vector<int> &preorder)
{
    int low = INT_MIN;
    int high = INT_MAX;
    int index = 0;

    return solve(preorder, low, high, index);
}

int main()
{

    return 0;
}
