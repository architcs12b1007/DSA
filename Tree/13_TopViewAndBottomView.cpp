#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Top view of a binary tree is the set of nodes visible when the tree is viewed from the top
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

// Approach: Need a 1-1 mapping for every horizontal distance and do LEVEL ORDER TRAVERSAL (IMP.)

void levelorderTraversal(Node *root, map<int, int> &hashMap)
{
    if (root == NULL)
        return;

    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        Node *currNode = temp.first;
        int hd = temp.second;
        // if(hashmap.find(hd)==hashmap.end())
        if (!hashMap.count(hd)) // delete this line for bottomView and everyhting is same
        {
            hashMap[hd] = currNode->data;
        }

        q.pop();

        if (currNode->left)
        {
            q.push(make_pair(currNode->left, hd - 1));
        }
        if (currNode->right)
        {
            q.push(make_pair(currNode->right, hd + 1));
        }
    }
}

// Time Complexity: O(N logN), Space Complexity:O(N)
vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> hashMap;
    levelorderTraversal(root, hashMap);

    for (auto &i : hashMap)
    {
        ans.push_back(i.second);
    }

    return ans;
}

int main()
{

    return 0;
}