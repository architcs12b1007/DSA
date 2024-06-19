#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// first traverse tree from left to right(level 1), then right to left(level 2) and so on.
// Also called SPIRAL TRAVERSAL (ZIGZAG TRAVERSAL)

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

// Approach: Use queue DS and use one variable leftToTight & one temp array to track order of insertion of level order nodes.(whether in correct order or in reverse order)

// Time Complexity:O(N), Space:O(N)

vector<int> zigZagTraversal(Node *root)
{
    vector<int> ans;
    queue<Node *> q;
    int leftToRight = false;
    if (root != NULL)
    {
        q.push(root);
    }

    while (!q.empty())
    {
        // Process level order
        int size = q.size();
        vector<int> temp(size);
        for (int i = 0; i < size; i++)
        {
            Node *currNode = q.front();
            q.pop();

            // normal insert or reverse insert
            int index = leftToRight ? i : size - i - 1;
            temp[index] = currNode->data;

            if (currNode->left)
            {
                q.push(currNode->left);
            }

            if (currNode->right)
            {
                q.push(currNode->right);
            }
        }
        leftToRight = !leftToRight;
        for (auto &i : temp)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

void preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);

    preorder(root->right);
}
int main()
{
    Node *root = new Node(10);
    Node *start = root;

    start->left = new Node(20);
    start->right = new Node(30);
    start = root->left;

    // start->left = new Node(40);
    start->right = new Node(50);
    start = root->right;

    start->left = new Node(60);
    start->right = new Node(70);

    // preorder(root);
    // cout << endl;

    vector<int> ans = zigZagTraversal(root);

    for (auto &v : ans)
    {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}