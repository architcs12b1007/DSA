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

// k is always less than or equal to n.
// Approach: reverse first k nodes and then do it recursively
// Time: O(N), Space:O(N/k) {but k can be 1 so, o(N)}

// If we want same last nodes if k is not divisible by n, then use the condition ==> if (count<k) then reverse last remaining nodes one more time.In this wat last remaining reverse 2 times and their original position wiil maintained.

Node *kReverse(Node *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    int count = 0;
    while (curr != NULL && count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    head->next = kReverse(curr, k);

    return prev;
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
    head = kReverse(head, 0);
    print(head);

    return 0;
}
