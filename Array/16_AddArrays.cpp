#include <iostream>
#include <vector>
using namespace std;

// Each array element represent a digit. Find sum of 2 arraya

// Time:O(max(n,m)) Space:O(1)
vector<int> findArraySum(vector<int> &a, vector<int> &b)
{
    int end1 = a.size() - 1;
    int end2 = b.size() - 1;
    vector<int> ans;
    int carry = 0;

    while (end1 >= 0 && end2 >= 0)
    {
        int sum = a[end1] + b[end2] + carry;
        carry = sum / 10;
        ans.push_back(sum % 10);
        end1--;
        end2--;
    }

    while (end1 >= 0)
    {
        int sum = a[end1] + carry;
        carry = sum / 10;
        ans.push_back(sum % 10);
        end1--;
    }

    while (end2 >= 0)
    {
        int sum = b[end2] + carry;
        carry = sum / 10;
        ans.push_back(sum % 10);
        end2--;
    }

    if (carry != 0)
    {
        ans.push_back(carry);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{

    return 0;
}