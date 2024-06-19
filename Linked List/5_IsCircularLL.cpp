#include <iostream>
#include <map>
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

// The circular linked list is a linked list where all nodes are connected to form a circle.
// In a circular linked list, the first node and the last node are connected to each other which forms a circle. There is no NULL at the end.

// Empty List is also Circular (Depend on the question)

// Approach1: If We reach at same node from where we starts(head is starting node), then it is circular
// Time: O(N), Space:O(1)

bool isCircular(Node *head)
{
    if (head == NULL)
        return true;

    Node *temp = head->next;

    while (temp != NULL && temp != head) // 2 conditions 1)Circular 2)Non-circular
    {
        temp = temp->next;
    }
    if (temp == NULL)
        return false;
    else
        return true;
}

// Approach 2: Using map data structure to track which node is visited or NOT.
// Time: O(N), Space:O(N)

// Detect loop in LL and circular LL as well (Use when to find both)

bool isCircular1(Node *head)
{
    if (head == NULL)
        return true; // given in question, empty list is circular
    map<Node *, bool> visited;

    while (head != NULL)
    {
        if (visited.count(head)) // visited.find(head)!=visited.end() OR visited[head]=true
        {
            return true;
        }
        else
        {
            visited[head] = true; // visited.insert({head,true});
        }

        head = head->next;
    }
    return false;
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

    cout << isCircular1(head) << endl;
    temp->next = head;
    cout << isCircular1(head) << endl;

    return 0;
}
