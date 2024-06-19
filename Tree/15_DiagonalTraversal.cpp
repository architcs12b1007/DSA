#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.
// If the diagonal element are present in two different subtress then left subtree diagonal element should be taken first and then right subtree

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

// Approach: When moving right child, do not increase horizontal distance but when go left child, decrease h.d by 1
// do increase level by 1.
vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    map<int, map<int, vector<int>>> hashMap;

    queue<pair<Node *, int>> q;

    q.push(make_pair(root, 0));
    int level = 0;

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            pair<Node *, int> temp = q.front();
            q.pop();
            Node *currNode = temp.first;
            int hd = temp.second;
            hashMap[hd][level].push_back(currNode->data);
            if (currNode->left)
            {
                q.push(make_pair(currNode->left, hd - 1));
            }

            if (currNode->right)
            {
                q.push(make_pair(currNode->right, hd)); // when move right, do not increase hd
            }
        }
        level++;
    }

    for (auto &i : hashMap)
    {
        for (auto &j : i.second)
        {
            for(auto &k:j.second){
                ans.push_back(k);
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}