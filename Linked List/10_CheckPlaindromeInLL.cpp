#include <iostream>
#include <vector>
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

// Approach 1:Create array and copy contents of LL into that array & it is easy to check palindrome in array
// Time: O(N), Space:O(N)

bool isPalindrome(Node *head)
{
    vector<int> v;
    Node *temp = head;

    while (temp != NULL)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }

    int start = 0, end = v.size() - 1;
    while (start <= end)
    {
        if (v[start] != v[end])
            return false;

        start++;
        end--;
    }

    return true;
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

// Approach 2: Find middle of linked lists. Reverse the Linked List after that middle element.Now, compare every element from start element and start of reverse List. Return ans as per condition.
// If you want to restore list originally, again reverse the LL after the middle element

// Time: O(N), Space:O(1)

Node *reverseLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *root = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;
    return root;
}

Node *middleofLinkedList(Node *head)
{ // return rightmost middle in case of even length
    if (head == NULL || head->next == NULL)
        return head;

    Node *fast = head->next;
    Node *slow = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;

        slow = slow->next;
    }

    return slow;
}

bool isPalindrome1(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    Node *middleNode = middleofLinkedList(head);

    Node *reverseHead = reverseLinkedList(middleNode);
    // print(reverseHead);
    Node *reversestart = reverseHead;
    Node *start = head;
    while (reversestart != NULL)
    {
        if (start->data != reversestart->data)
        {
            return false;
        }
        start = start->next;
        reversestart = reversestart->next;
    }

    return true;
}

int main()
{
    Node *head = new Node(10);
    Node *temp = head;

    temp->next = new Node(10);
    temp = temp->next;

    // temp->next = new Node(20);
    // temp = temp->next;

    // temp->next = new Node(20);
    // temp = temp->next;

    cout << isPalindrome(head) << endl;
    cout << isPalindrome1(head) << endl;
    return 0;
}
