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

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Approach 1:Create array and copy contents of LL into that array & it is easy to check palindrome in array
// Time: O(N), Space:O(N)

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

Node *add2NumbersInLL(Node *first, Node *second)
{
    Node *reverseFirst = reverseLinkedList(first);
    Node *reverseSecond = reverseLinkedList(second);
    Node *dummy = new Node(-1);
    Node *ans = dummy;
    int carry = 0, digit, sum;

    while (reverseFirst != NULL && reverseSecond != NULL)
    {
        sum = reverseFirst->data + reverseSecond->data + carry;
        digit = sum % 10;
        carry = sum / 10;
        ans->next = new Node(digit);
        ans = ans->next;
        cout << digit << " ";
        reverseFirst = reverseFirst->next;
        reverseSecond = reverseSecond->next;
    }

    while (reverseFirst != NULL)
    {
        sum = reverseFirst->data + carry;
        digit = sum % 10;
        carry = sum / 10;
        ans->next = new Node(digit);
        cout << digit << " ";
        ans = ans->next;
        reverseFirst = reverseFirst->next;
    }

    while (reverseSecond != NULL)
    {
        sum = reverseSecond->data + carry;
        digit = sum % 10;
        cout << digit << " ";
        carry = sum / 10;
        ans->next = new Node(digit);
        ans = ans->next;
        reverseSecond = reverseSecond->next;
    }
    if (carry > 0)
    {
        ans->next = new Node(carry);
    }
    ans = dummy->next;
    //  delete dummy;
    ans = reverseLinkedList(ans);

    return ans;
}

int main()
{
    Node *first = new Node(8);
    Node *temp = first;

    temp->next = new Node(5);
    temp = temp->next;

    temp->next = new Node(2);
    temp = temp->next;

    temp->next = new Node(1);
    temp = temp->next;

    Node *second = new Node(4);
    temp = second;

    temp->next = new Node(6);
    temp = temp->next;

    temp->next = new Node(7);
    temp = temp->next;

    Node *head = add2NumbersInLL(first, second);
    cout<<endl;
    print(head);

    return 0;
}
