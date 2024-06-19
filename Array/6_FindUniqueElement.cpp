#include <iostream>
#include <vector>

using namespace std;

// size of array 2*M+1, where M elements occur twice and one number is present only once.
// Approach:Xor of duplicate elements become zero.so it will unique elements (a^a=0 and 0^a=a)
// xor operations are ASSOCIATIVE
// Time Complexity:O(N), Space:O(1)
int UniqueElement(vector<int> v)
{
    int ans = 0;
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ v[i];
    }

    return ans;
}
int main()
{

    return 0;
}