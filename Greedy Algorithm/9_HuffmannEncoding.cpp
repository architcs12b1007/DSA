#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Given a string S of distinct character of size N and character S[i] has f[i] frequency. Your task is to build the Huffman tree print all the huffman codes in preorder traversal of the tree.

// Note: While merging if two nodes have the same value, then the node which occurs at first will be taken on the left of Binary Tree and the other one to the right, otherwise Node with less value will be taken on the left of the subtree and other one to the right.

// Approach: Chhose 2 min values from frequency array & then push their sum and again choose 2min value.
// Continue in this way (similar to Min caost of ropes)
// All characters sre in the leaf node

// Time Complexity:O(N logN)    Space:O(N)

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

void preOrderTraversal(Node *root, vector<string> &ans, string s)
{

    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(s);
        return;
    }

    preOrderTraversal(root->left, ans, s + '0');

    preOrderTraversal(root->right, ans, s + '1');
}

class compare
{

public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

vector<string> huffmanCodes(string S, vector<int> f, int N)
{
    vector<string> ans;
    priority_queue<Node *, vector<Node *>, compare> pq; // minheap;

    for (int i = 0; i < N; i++)
    {
        Node *temp = new Node(f[i]);
        pq.push(temp);
    }

    Node *head;

    while (pq.size() > 1)
    {
        Node *leftNode = pq.top();
        pq.pop();

        Node *rightNode = pq.top();
        pq.pop();

        Node *head = new Node(leftNode->data + rightNode->data);
        head->left = leftNode;
        head->right = rightNode;
        pq.push(head);
    }

    Node *root = pq.top();
    string s1 = "";

    preOrderTraversal(root, ans, s1);
    return ans;
}

int main()
{

    return 0;
}