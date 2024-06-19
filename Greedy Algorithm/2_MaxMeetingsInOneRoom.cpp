#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Same as previous one.
// Print all meeting numbers.
// Note: If two meetings can be chosen for the same slot then choose meeting with smaller index in the given array.

// Time Complexity:O(N logN)  space:O(N)

struct meeting
{
    int start;
    int end;
    int pos;
};

class compare
{
public:
    bool operator()(meeting A, meeting B)
    {
        if (A.end < B.end)
            return true;
        else if (A.end > B.end)
            return false;
        else if (A.pos < B.pos)
            return true;

        return false;
    }
};

vector<int> maxMeetings(int N, vector<int> &start, vector<int> &end)
{
    vector<int> ans;
    vector<meeting> time(N);

    for (int i = 0; i < N; i++)
    {
        time[i].start = start[i];
        time[i].end = end[i];
        time[i].pos = i + 1;
    }

    sort(time.begin(), time.end(), compare());

    ans.push_back(time[0].pos);
    int limitEndTime = time[0].end;

    for (int i = 1; i < N; i++)
    {
        if (limitEndTime < time[i].start)
        {
            limitEndTime = time[i].end;
            ans.push_back(time[i].pos);
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{

    return 0;
}