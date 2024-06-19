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

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

// Approach: Take dummmy node and then normal comparision
// Time: O(N), Space:O(1)

Node *sortedTwoLists(Node *first, Node *second)
{
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;

    Node *dummy = new Node(-1);
    Node *head = dummy;
    Node *firstCurr = first;
    Node *secondCurr = second;
    while (firstCurr != NULL && secondCurr != NULL)
    {
        if (firstCurr->data >= secondCurr->data)
        {
            dummy->next = secondCurr;
            dummy = secondCurr;
            secondCurr = secondCurr->next;
        }
        else
        {
            dummy->next = firstCurr;
            dummy = firstCurr;
            firstCurr = firstCurr->next;
        }
    }

    if (firstCurr != NULL)
    {
        dummy->next = firstCurr;
    }
    if (secondCurr != NULL)
    {
        dummy->next = secondCurr;
    }

    dummy = head;
    head = head->next;
    dummy->next = NULL;

    delete dummy;

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

int main()
{
    Node *first = new Node(10);
    Node *temp = first;

    temp->next = new Node(20);
    temp = temp->next;

    temp->next = new Node(30);
    temp = temp->next;

    temp->next = new Node(40);
    temp = temp->next;

    Node *second = new Node(5);
    temp = second;

    temp->next = new Node(10);
    temp = temp->next;

    temp->next = new Node(15);
    temp = temp->next;

    temp->next = new Node(20);
    temp = temp->next;

    Node *head = sortedTwoLists(first, second);
    cout << endl;
    print(head);

    return 0;
}
