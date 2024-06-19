#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Greedy algorithm ? Find optimal solution that is best for that particular moment of time.
// Choose local optimum solution at particalar instant
// eg: Use sort, max, min, custom operator, set , priority queue

// 1 meeting room. There are N meetings in the form of (start[i], end[i])
// Maximum number of meetings in the meeting room when only one meeting can be held in the meeting room at a particular time?
// Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

// Approach: we should choose meetings that end early and utilize the remaining time for more meetings.

// Time Complexity:O(NlogN)   Space:O(N)

int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> time;
    int ans = 1; // 1st meeting is always performed

    for (int i = 0; i < n; i++)
    {
        time.push_back(make_pair(end[i], start[i]));
    }

    sort(time.begin(), time.end());

    int endAns = time[0].first;

    for (int i = 1; i < n; i++)
    {
        if (endAns < time[i].second)
        {
            ans++;
            endAns = time[i].first;
        }
    }

    return ans;
}
int main()
{

    return 0;
}