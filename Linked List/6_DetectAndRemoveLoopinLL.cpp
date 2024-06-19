#include <iostream>
using namespace std;

// Detect cycle in Linked List
// Remove cycle from Linked List
// Beginning/Start node of loop in Linked List

// Floyd’s cycle finding algorithm or Hare-Tortoise algorithm is a pointer algorithm that uses only two pointers, moving through the sequence at different speeds. This algorithm is used to find a loop in a linked list. It uses two pointers one moving twice as fast as the other one.

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

// Approach1: Using map data structure to track which node is visited or NOT. Can also give the positions of element where loop is present (beginning Node)
// Time: O(N), Space:O(N)

// Approach: Using 2 pointers: fast and slow, Floyd’s cycle finding algorithm
// Time: O(N), Space:O(1)

// Why would they meet? Once slow pointer enters in loop, fast pointer is already in the loop, so after that on each iteration, their distance between them in anitclockwise direction will get reduce by 1. So, they finally meet.

Node *floydDetectLoop(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && slow != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;

        slow = slow->next;

        if (fast == slow)
            return slow;
    }

    return NULL;
}

// Approach: Find point of intersection of node from above floyd detect loop.
// After that, point slow pointer to head.
// Move slow anf fast pointer with same pace of speed 1 and their point of intersection is starting node

// Logic: 2(A+B+y.C)=(A+B+x.C), where C is length of circular loop, A is distance by slow pointer when it comes to loop for first time, B is distance from starting Node to point of intersection ==>A+B=(x-2y)C,
// A+B= n*C {A+B means cycle complete}
// Now slow points to head & needs to travel A, fast pointer needs to travel C-B(same distance) to meet at starting node if both move at same speeds.

Node *staringNodeOfLoop(Node *head)
{
    Node *intersectionNode = floydDetectLoop(head);
    if (intersectionNode != NULL)
    {
        Node *slow = head;
        // Node *fast = intersectionNode;
        while (slow != intersectionNode)
        {
            slow = slow->next;
            intersectionNode = intersectionNode->next; // fast = fast->next;
        }
        return slow;
    }
    else
    {
        return NULL;
    }
}

void removeLoop(Node *head)
{
    Node *startNode = staringNodeOfLoop(head);
    if (startNode != NULL)
    {
        Node *temp = startNode;
        while (temp->next != startNode)
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }
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
    Node *loop = temp;

    temp->next = new Node(30);
    temp = temp->next;

    temp->next = new Node(40);
    temp = temp->next;
    temp->next = loop;
    if (floydDetectLoop(head) != NULL)
    {
        cout << "Cycle is Present" << endl;
    }
    else
    {
        cout << "Cycle is NOT Present" << endl;
    }

    Node *ans = staringNodeOfLoop(head);
    cout << ans->data << endl;

    removeLoop(head);

    print(head);
    return 0;
}

// Solved through 2 approaches:
// 1)Take data structure of MAP
// 2)Floyd Cycle Detection Algo

// Homework: Remove Loop (5 ways), Cycle Detect (3 ways) [2 are already done]