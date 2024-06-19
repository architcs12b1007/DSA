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

// Approach 1: Take three counters to track number of 0s,1s and 2s.Then traverse through Linked List & replaced with 0s,1s and 2s
// Time: O(N), Space:O(1)

Node *sortList(Node *head)
{
    int zeroCount = 0, oneCount = 0, twoCount = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeroCount++;
        }
        else if (temp->data == 1)
        {
            oneCount++;
        }
        else if (temp->data == 2)
        {
            twoCount++;
        }
        temp = temp->next;
    }

    temp = head;

    while (zeroCount--)
    {
        temp->data = 0;
        temp = temp->next;
    }

    while (oneCount--)
    {
        temp->data = 1;
        temp = temp->next;
    }

    while (twoCount--)
    {
        temp->data = 2;
        temp = temp->next;
    }

    return head;
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
// Do not want to replace data
// Appraoch 2: Create 3 linked list of zero, one and two and add data as we are traversing.
// Create dummy nodes as well before inserting node so that we have to use less if and null conditions check

// Time Complexity:O(N), Space:O(1). {only 1 time traversal of LL unlike previous one 2 times}

void insertAtTail(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = curr;
}

Node *sortList1(Node *head)
{
    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);

    Node *zeroTail = zeroHead;
    Node *oneTail = oneHead;
    Node *twoTail = twoHead;

    Node *curr = head;
    // create separate list of 0s,1s, 2s
    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            insertAtTail(zeroTail, curr);
        }
        else if (curr->data == 1)
        {
            insertAtTail(oneTail, curr);
        }
        else if (curr->data == 2)
        {
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }

    // merge 3 sublist
    if (oneHead->next != NULL) // 1s list not empty
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // setup head node
    head = zeroHead->next;

    // delete dummy nodes;
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

int main()
{
    Node *head = new Node(1);
    Node *temp = head;

    temp->next = new Node(2);
    temp = temp->next;

    temp->next = new Node(2);
    temp = temp->next;

    temp->next = new Node(1);
    temp = temp->next;

    temp->next = new Node(1);
    temp = temp->next;

    temp->next = new Node(1);
    temp = temp->next;

    head = sortList1(head);
    print(head);

    return 0;
}
