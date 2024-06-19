#include <iostream>
#include <vector>
using namespace std;

// Given are N boards of with length of each given in the form of array, and K painters, such that each painter takes 1 unit of time to paint 1 unit of the board.

// The task is to find the minimum time to paint all boards under the constraints that any painter will only paint continuous sections of boards.

// N = 4, A = {10, 20, 30, 40}, K = 2   1=<k<=N

// Output : 60

// Approach: Need to use all k painters in order to find minima. Do k contigous partition of array, find maxima in these paritions. We have many such partiions, return min of max among these parttions.
// Answer search space is (0,Sum of all elements of array)
// Same logic as previous one. (BOOK ALLOCATION)

int findLargestMinTime(vector<int> &boards, int k)
{
}

int main()
{

    return 0;
}