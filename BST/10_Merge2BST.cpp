#include <iostream>
#include <vector>
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

void inorderTraversal(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left, ans);
    ans.push_back(root->data);
    inorderTraversal(root->right, ans);
}

void merge2SortedArrays(vector<int> v1, vector<int> v2, vector<int> &ans)
{
    int n1 = v1.size();
    int n2 = v2.size();

    int s1 = 0, s2 = 0;

    while (s1 < n1 && s2 < n2)
    {

        if (v1[s1] <= v2[s2])
        {
            ans.push_back(v1[s1]);
            s1++;
        }
        else
        {
            ans.push_back(v2[s2]);
            s2++;
        }
    }

    while (s1 < n1)
    {
        ans.push_back(v1[s1]);
        s1++;
    }

    while (s2 < n2)
    {
        ans.push_back(v2[s2]);
        s2++;
    }
}

Node *inorderToBST(vector<int> v, int start, int end)
{
    if (start > end)
        return NULL;

    int mid = start + (end - start) / 2;

    Node *temp = new Node(v[mid]);
    temp->left = inorderToBST(v, start, mid - 1);
    temp->right = inorderToBST(v, mid + 1, end);

    return temp;
}
// Approach1: 1)Find inorder of both BST
// 2)Find sorted array from two sorted arrays
// 3)Build BST from sorted array(inorder)

// Time Complexity:O(m+n) Space Complexity:O(m+n)

Node *mergeBST(Node *root1, Node *root2)
{
    // Write your code here.
    vector<int> v1, v2, ans;

    inorderTraversal(root1, v1);
    inorderTraversal(root2, v2);

    merge2SortedArrays(v1, v2, ans);

    return inorderToBST(ans, 0, ans.size() - 1);
}
// Traverse right, process nodes, traverse left
void convertIntoSortedDLL(Node *root, Node *&head)
{
    if (root == NULL)
        return;

    convertIntoSortedDLL(root->right, head);

    root->right = head;

    if (head != NULL)
        head->left = root;

    head = root;

    convertIntoSortedDLL(root->right, head);
}

Node *merge2SortedLL(Node *head1, Node *head2)
{
    if (head1 == NULL && head2 == NULL)
    {
        return NULL;
    }

    Node *head = new Node(-1);
    Node *temp = head;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data >= head2->data)
        {
            temp->right = head2;
            head2->left = temp;
            head2 = head2->right;
            temp = head2;
        }
        else
        {
            temp->right = head1;
            head1->left = temp;
            head1 = head1->right;
            temp = head1;
        }
    }

    if (head1 != NULL)
    {
        temp->right = head1;
        head1->left = temp;
    }

    if (head2 != NULL)
    {
        temp->right = head2;
        head2->left = temp;
    }

    head = head->right;
    head->left = NULL;

    return head;
}
int countNodes(Node *root)
{
    int count = 0;
    while (root != NULL)
    {
        count++;
        root = root->right;
    }

    return count;
}
// n is total nodes in DLL
Node *sortedLLToBST(Node *&head, int n)
{
    if (n <= 0 || head == NULL)
        return NULL;

    Node *left = sortedLLToBST(head, n/2);
    Node *root = head;
    root->left = left;
    head = head->right;
    root->right = sortedLLToBST(head, n - n / 2 - 1);

    return root;
}

// Approach 2: 1)Covert BST into a sorted Doubly LinkedList {Time:O(n), Space:O(h) h is height of given BST}
// 2)Merge 2 sorted Linked Lists {Time:O(n+m), Space:O(1)}
// 3)Convert sorted Linked Lists into a BST:{Time:O(n+m), Space:O(h1+h2) h1,h2 are heights of given BST}

// Time Complexity:O(n+m) Space:O(h1+h2), h1 and h2 are heights of given BST

Node *mergeBST1(Node *root1, Node *root2)
{
    // Write your code here.
    Node *head1 = NULL;
    Node *head2 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    Node *head = merge2SortedLL(head1, head2);
    int n = countNodes(head);

    return sortedLLToBST(head, n);
}

int main()
{

    return 0;
}