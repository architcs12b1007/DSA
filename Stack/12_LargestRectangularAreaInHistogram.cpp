#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

// heights = [2,1,5,6,2,3]     Output: 10  {5,5(6)}

// Approach 1: (Nested loops), for each height(L is constant), track left and right rectangles(to find width) can be drawn and atlast max area can be retrieved. Time:(O(N^2))

// Approach 2: For each height, track prevSmaller and nextSmaller index with the help of stack and now width is (nextSmallerIndex-prevSmallerIndex-1) and find max area in that way. Time:O(N) Space:O(N)

int largestRectangleArea(vector<int> &heights)
{
    stack<pair<int, int>> s;
    int ans = 0;
    int n = heights.size();

    vector<int> nextSmaller(n); // to store indices fro each height
    vector<int> prevSmaller(n); // to store indices fro each height

    s.push({-1, -1}); // 1st to store element and 2nd to store index {-1 is left to o index}

    for (int i = 0; i < n; i++)
    {

        while (heights[i] <= s.top().first)
        {
            s.pop();
        }
        prevSmaller[i] = s.top().second; // Can also be done with stack<int> to store indices and acccess element using arr[s.top()]
        s.push({heights[i], i});
    }

    while (!s.empty())
    {
        s.pop();
    }

    s.push({-1, n}); // {n is right to n-1 index}

    for (int i = n - 1; i >= 0; i--)
    {

        while (heights[i] <= s.top().first)
        {
            s.pop();
        }
        nextSmaller[i] = s.top().second;
        s.push({heights[i], i});
    }

    for (int i = 0; i < n; i++)
    {
        int area = heights[i] * (nextSmaller[i] - prevSmaller[i] - 1);
        ans = max(area, ans);
    }

    return ans;
}

int main()
{

    return 0;
}