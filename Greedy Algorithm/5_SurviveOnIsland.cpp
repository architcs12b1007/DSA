#include <iostream>
#include <vector>
using namespace std;

// Ishika got stuck on an island. There is only one shop on this island and it is open on all days of the week except for Sunday. Consider following constraints:

// N – The maximum unit of food you can buy each day.
// S – Number of days you are required to survive.
// M – Unit of food required each day to survive.
// Currently, it’s Monday, and she needs to survive for the next S days.
// Find the minimum number of days on which you need to buy food from the shop so that she can survive the next S days, or determine that it isn’t possible to survive

// Input: S = 10, N = 16, M = 2    Output: 2

// Input: S = 10, N = 20, M = 30   Output: -1

// Time:O(1)  Space:O(1)
int minimumDays(int S, int N, int M)
{
    // code here
    if (N < M)
    {
        return -1;
    }

    int firstWeekFood = (N - M) * 6;

    // check for Sunday i.e. food is available on Sunday
    if (firstWeekFood < M && S >= 7)
    {
        return -1;
    }

    int totalFood = S * M;

    int ans = totalFood / N;

    if (totalFood % N != 0)
        ans++;

    return ans;
}
int main()
{

    return 0;
}