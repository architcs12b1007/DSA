#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Given a set of N jobs where each jobi has a deadline and profit associated with it.

// Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.

// Find the number of jobs done and the maximum profit.

// Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.

// 1 <= N <= 105
// 1 <= Deadline <= N
// 1 <= Profit <= 500

// N = 4   Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
// Output:
// 2 60

// N = 5   Jobs = {(1,2,100),(2,1,19),(3,2,27),
//         (4,1,25),(5,1,15)}
// Output: 2 127

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

static bool comparator(Job a, Job b)
{
    return a.profit > b.profit;
}

// Time:O(N log N)  Space:O(N)
vector<int> JobScheduling(Job arr[], int n)
{
    vector<int> scheduler(n + 1, -1); // i-index
    vector<int> ans;

    int numberOfJobs = 0, maxProfit = 0;

    sort(arr, arr + n, comparator);

    for (int i = 0; i < n; i++)
    {
        if (scheduler[arr[i].dead] == -1)
        {
            maxProfit += arr[i].profit;
            scheduler[arr[i].dead] = arr[i].id;
            numberOfJobs++;
        }
        else // find the empty index if possible (as each job takes 1 unit of time only)
        {
            int index = arr[i].dead;
            while (scheduler[index] != -1)
            {
                index--;
            }

            if (index > 0)
            {
                maxProfit += arr[i].profit;
                scheduler[index] = arr[i].id;
                numberOfJobs++;
            }
        }
    }

    ans.push_back(numberOfJobs);
    ans.push_back(maxProfit);
    return ans;
}


// Can be done in a better way using disjoint set
int main()
{

    return 0;
}