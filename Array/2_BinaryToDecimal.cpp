#include <iostream>
#include <math.h>
using namespace std;

int BinaryToDecimal(string s)
{
    int ans = 0;

    int size = s.length();

    for (int i = size - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            ans += pow(2, size - i - 1);
        }
    }

    return ans;
}
int main()
{
    string s = "10011";
    cout << BinaryToDecimal(s) << endl;

    return 0;
}