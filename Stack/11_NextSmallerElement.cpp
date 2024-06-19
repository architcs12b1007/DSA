#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Given an array, print the Next Smaller Element (NSE) for every element.
// The NSE for an element x is the FIRST ELEMENT to right of x that has value strictly smaller than x
// Elements for which no smaller element exist (on the right side), consider NSE as -1

// i/P: [2,1,4,3]  o/p:[1,-1,3,-1]  0<=arr[i]<=10^9

// Approach 1: Brute force (two nested loop) Time:O(N*2) Space:O(1)

// Approach 2:Use stack data structure and do processing from end and just pop elemets from stack
// when larger number or equal is present than current element.

// Time Complexity:O(N) Space Complexity:O(N), all the elements in the stack are push and popped atmost once.

// Input: [4, 8, 5, 2, 25]
// Output: [2, 5, 2, -1, -1]

vector<int> nextSmallerElement(vector<int> &arr, int n)
{

    stack<int> s;
    vector<int> ans(n);

    s.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {
        int top = s.top();
        if (arr[i] > top)
        {
            ans[i] = top;
            s.push(arr[i]);
        }
        else
        {
            // removing elements greater than or equal to arr[i]
            while (arr[i] <= top)
            {
                s.pop();
                top = s.top();
            }
            ans[i] = top;
            s.push(arr[i]);
        }
    }

    return ans;
}

vector<int> nextSmallerElement1(vector<int> &arr, int n)
{

    stack<int> s;
    vector<int> ans(n);

    s.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {
        // removing elements greater than or equal to arr[i]
        while (arr[i] <= s.top())
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(arr[i]);
    }

    return ans;
}

// Previous Smaller Element: Follow same approach as above but start loop from 0 to n-1
int main()
{

    return 0;
}