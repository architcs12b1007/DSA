#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Approach: Iteration: Take 3 pointers: prev,curr, forward & do the processing
// Time: O(N), Space:O(1)

Node *reverseLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;

    while (curr != NULL)
    {

        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

// Recursive Solution:

// Time:O(N), Space:O(N)

Node *reverseLLRecursive(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *root = reverseLLRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return root;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(10);
    Node *temp = head;

    temp->next = new Node(20);
    temp = temp->next;

    temp->next = new Node(30);
    temp = temp->next;

    temp->next = new Node(40);
    temp = temp->next;

    print(head);

    // head = reverseLinkedList(head);
    head = reverseLLRecursive(head);
    print(head);

    return 0;
}

// Homework: Reverse Doubly Linked List