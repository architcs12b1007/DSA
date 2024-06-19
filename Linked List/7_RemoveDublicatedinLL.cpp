#include <iostream>
#include <unordered_map>
using namespace std;

// Remove Duplicated from a sorted or unsorted Linked Lists
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

// Approach: Sliding window and take 2 pointers: start and end.
// Time: O(N), Space:O(1)

Node *removeDublicatedFromSortedLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *start = head;
    Node *end = head->next;
    while (end != NULL)
    {
        while (end != NULL && start->data == end->data)
        {
            Node *temp = end;
            end = end->next;
            delete temp;
        }
        start->next = end;
        start = end;
        if (end != NULL)
            end = end->next;
    }
    return head;
}
// Approach: If next element is same as prev one, then delete this elemet & prev pointer point to next to next element

Node *removeDublicatedFromSortedLL1(Node *head)
{
    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->next != NULL && curr->data == curr->next->data)
        {
            Node *nodeToDelete = curr->next;
            curr->next = curr->next->next;
            delete nodeToDelete;
        }
        else
        {
            curr = curr->next;
        }
    }

    return head;
}

// UNSORTED Linked LIST.

// Approach 1: For each element of LL, check aaage ke saare elements fot that element & remove it if it is found again. Time Complexity:O(N2), Space:O(1)

// Approach 2:Sort Linked List and then do above logic. Time:O(nlogn) Space:O(1)

// Approach 3: Use map data structure to maintain unique elements
// Time Complexity:O(N)   Space complexity:O(N)

Node *removeDublicatedFromUnsortedLL(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    unordered_map<int, bool> visited;

    while (curr != NULL)
    {
        if (visited[curr->data])
        {
            Node *deleteToNode = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete deleteToNode;
        }
        else
        {
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
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

    return 0;
}

// Homework: Divide Circular LL into two half circular LL.