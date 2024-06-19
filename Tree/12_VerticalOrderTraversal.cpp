#include <iostream>
#include <vector>
#include <map>
using namespace std;
// find the vertical traversal of binary tree starting from the leftmost level to the rightmost level.
// If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.
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

// Approach: Think root (at origin) as we put it on number line. For each left child, we have h.d.subtract by -1 and v.d increase by 1.For each right child, we have h.d. increase by 1 and v.d increase by 1.

// Mapping: Horizontal distance --> vertical level wise nodes (level--->list of nodes)
// Use data structure: map<int,map<int,vector<int>>> {H.D : (Level:List of nodes)}

// Do level order traversal while traversing through nodes. queue<pair<Nodes*,pair<int,int>>> {Nodes, H.d., level}. Can also do any other traversal like preorder.

void preorderTraversal(Node *root, map<int, map<int, vector<int>>> &hashMap, int hd, int level)
{
    if (root == NULL)
    {
        return;
    }

    hashMap[hd][level].push_back(root->data);

    preorderTraversal(root->left, hashMap, hd - 1, level + 1);
    preorderTraversal(root->right, hashMap, hd + 1, level + 1);
}

// Time Complexity:O(NlogN) Space Complexity:O(N)

vector<int> verticalOrder(Node *root)
{
    map<int, map<int, vector<int>>> hashMap;
    vector<int> ans;
    if (root == NULL)
        return ans;

    preorderTraversal(root, hashMap, 0, 0);

    for (auto &i : hashMap) 
    {
        for (auto &j : i.second)
        {
            for (auto &k : j.second)
            {
                ans.push_back(k);
            }
        }
    }

    return ans;
}

int main()
{
    Node *root = new Node(10);
    Node *start = root;

    start->left = new Node(20);
    start->right = new Node(30);
    start = root->left;

    start->left = new Node(40);
    start->right = new Node(50);
    start = root->right;

    start->left = new Node(60);
    start->right = new Node(70);

    vector<int> ans = verticalOrder(root);

    for (auto &v : ans)
    {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}