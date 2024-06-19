#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

//  While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer.

// Time Complexity: O(N) Space Complexity:O(26)

string FirstNonRepeating(string A)
{

    queue<char> q;
    unordered_map<char, int> count; // to check whteher repeating or NOT

    int size = A.length();
    string ans;

    for (int i = 0; i < size; i++)
    {
        count[A[i]]++;
        q.push(A[i]);

        while (!q.empty() && count[q.front()] > 1)
        {
            q.pop();
        }

        if (q.empty())
        {
            ans.push_back('#');
        }
        else
        {
            ans.push_back(q.front());
        }
    }

    return ans;
}

int main()
{

    return 0;
}