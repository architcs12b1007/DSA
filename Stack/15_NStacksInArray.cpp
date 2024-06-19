#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Approach:1) top[]: repersent index of top element of N stacks
// { initially, -1 to indicate that all stacks are empty}

// 2) next[]: This is of size S.{ next[i] initialized as i+1 , next[S-1]=-1, all slots are free}

// -point to next free space in thae array
// -it also tracks next indices of each stack top.

// 3) free  variable is initialized as 0.(to track starting index of free space)

// Time:O(1) for both push & pop operation. Space:Max(S,N)

class NStack
{
public:
    // Initialize your data structure.
    int *arr;
    int *top;
    int *next;
    int free;
    int N, S;
    // N stacks using an array of size S
    NStack(int N, int S)
    {
        // Write your code here.
        this->N = N;
        this->S = S;
        arr = new int[S];
        top = new int[N];
        next = new int[S];

        for (int i = 0; i < N; i++)
            top[i] = -1; // initially all S stacks are empty.

        for (int i = 0; i < S - 1; i++)
            next[i] = i + 1; // points to next free element

        next[S - 1] = -1;

        free = 0; // initially 0 index is free
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        m--; // 0-indexing
        if (free == -1)
        {
            return false;
        }

        int i = free;

        free = next[i];

        next[i] = top[m];
        top[m] = i;

        arr[i] = x;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.

        m--; // 0-indexing

        if (top[m] == -1)
        {
            return -1;
        }
        int current = top[m];

        top[m] = next[current];

        next[current] = free;
        free = current;

        return arr[current];
    }
};

int main()
{

    return 0;
}