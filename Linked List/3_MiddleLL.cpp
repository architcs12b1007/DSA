#include <iostream>
using namespace std;

// Return middle of Linked List: In case of even nodes, return nodes that is farther from head nodes
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

// Approach 1: Find length of linked list. in case of odd, return node of (len/2)+1. In case of even, return node of (len/2)+1. (Two times traversal of LL)

// Approach 2: Take 2 pointers(players):one is moving with 1 and other is moving with 2. When faster pointer reaches to end, sloers one will be at middle. (Single time traversal of LL)
// Time: O(N), Space:O(1)

Node *findMiddle(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *slow = head;
    Node *fast = head->next;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->next;
}

Node *findMiddle1(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
    }

    return slow;
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

    // temp->next = new Node(50);
    // temp = temp->next;

    Node *middle = findMiddle1(head);
    cout << middle->data << endl;

    return 0;
}
