#include <iostream>
#include <vector>
using namespace std;

// Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers. If it is not possible(elements in descending order), then give answer in ascending order.

// Approach 1: Find all permutations and store them and then search for given permutation and then give next permutation. Time:O(N!*N)  Space:O(N!*N)

// Approach 2:Find the break-point, i: Break-point means the first index i from the back of the given array where arr[i] becomes smaller than arr[i+1].
// If such a break-point does not exist, give ans in ascending order
// If a break-point exists:
// Find the smallest number i.e. > arr[i] (i.e. from index i+1 to n-1) and swap it with arr[i].
// Reverse the entire right half(i.e. from index i+1 to n-1) of index i.

// Time Complexity:O(N)  Space:O(1)

vector<int> nextGreaterPermutation(vector<int> &A)
{
    // Write your code here.
    vector<int> ans;
    int breakIndex = 0;
    int size = A.size();
    for (int i = size - 1; i > 0; i--)
    {
        if (A[i] > A[i - 1])
        {
            breakIndex = i - 1;
            break;
        }
    }

    if (breakIndex == 0)
    {
        for (int i = size - 1; i >= 0; i--)
        {
            ans.push_back(A[i]);
        }
        return ans;
    }

    int nextGreaterElementIndex = size - 1;

    for (int i = breakIndex + 1; i < size; i++)
    {
        if (A[breakIndex] > A[i])
        {
            nextGreaterElementIndex = i - 1;
            break;
        }
    }

    swap(A[breakIndex], A[nextGreaterElementIndex]);

    int start = breakIndex + 1, end = size - 1;

    while (start < end)
    {
        swap(A[start], A[end]);
        start++;
        end--;
    }

    return A;
}

int main()
{
    return 0;
}