#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void solve(vector<long long int> &ans, unordered_set<long long int> &memo, int n, long long int val)
{
    if (n == 40 || memo.count(val))
        return;

    ans.push_back(val);
    memo.insert(val);

    solve(ans, memo, n + 1, 2 * val + 1);
    solve(ans, memo, n + 1, 2 * val - 1);
}

int main()
{
    vector<long long int> ans;
    unordered_set<long long int> memo;

    long long int val = 1;
    int n = 0;

    solve(ans, memo, n, val);

    cout << ans.size();
    return 0;
}
