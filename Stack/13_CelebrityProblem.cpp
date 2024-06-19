#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not. (if NOT, return -1)

// A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.

// Input:
// N = 3
// M[][] = {{0 1 0},
//          {0 0 0},
//          {0 1 0}}
// Output: 1

// Approach 1: Check for rows(say i) which has all zeros and check for same colum i such that it has all 1 (except M[i][i]), then i is the celebrity  Time:O(N2) Space:O(1)

// Approach 2: Use stack and push all people in the stack (0 to n-1).Repeat until size of stack is 1, pop 2 elements from the stack(A,B). If A knows B & B Not knows A: add B.  If B knows A & A Not knows B: add A.

// Follows elimination technique:  Time:O(N)  Space:O(N)
int celebrity(vector<vector<int>> &M, int n)
{
    // code here

    stack<int> s;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (M[a][b] == 1 && M[b][a] == 0)
        {
            s.push(b); // b can be celebrity
        }
        else if (M[b][a] == 1 && M[a][b] == 0)
        {
            s.push(a); // a can be celebrity
        }
        // else{
        //     // neither a nor b can be celebrity
        // }
    }

    if (s.size() == 1)
    {

        int index = s.top(); // can be potential celebrity

        for (int i = 0; i < n; i++)
        {
            if (M[index][i] == 1)
                return -1;

            if (i != index && M[i][index] == 0)
                return -1;
        }
    }
    else
        return -1;

    return s.top();
}

// Efficient approach of celebrity problem

// We will not use any extra space as will use spaces M[i][i] for storing whether i th person is a celebrity or not as these are by default 0, so if we find ith person is not a celebrity then we will mark M[i][i] as 1

// Time:O(N),  Space:O(1)

// Can be done using 2 pointer approaches. One point to start and one poin to end celebrity. Compare them and reduce the search bar by comapring 2 pointers using above logic.
int main()
{

    return 0;
}