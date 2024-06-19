#include <iostream>
#include <vector>
using namespace std;

// ‘pages[i]’ represents the number of pages in the ‘i-th’ book. There are ‘m’ number of students, and the task is to allocate all the books(N) to the students.

// Allocate books in a way such that:

// Each student gets at least one book.
// Each book should be allocated to a student.
// Book allocation should be in a contiguous manner.

// You have to allocate the books to ‘m’ students such that the MAXIMUM number of pages assigned to a student is MINIMUM.

// 2 <= 'n' <= 10 ^ 3
// 1 <= 'm' <= 10 ^ 3
// 1 <= 'arr[i]' <= 10 ^ 9
// The sum of all arr[i] does not exceed 10 ^ 9

// Aprroach: The answer lies between 0 and sum of all pages, (0,sum)
// 0 cannot be answer (each student gets atleast one book)
// Sum: When we have 1 student and he gets all the books

bool isPossible(vector<int> &arr, int n, int m, int numPages)
{

    int countStudent = 1;
    int currSum = 0;

    for (int i = 0; i < n; i++)
    {
        // each student sshould get less than oe equal to NumPages (in book)
        if (numPages < arr[i]) // imp condition (atleast 1 book should be alloted)
        {
            return false;
        }

        if (currSum + arr[i] <= numPages)
        {
            currSum += arr[i];
        }
        else
        {
            countStudent++;
            if (countStudent > m) // if (countStudent > m || numPages < arr[i])
                return false;

            currSum = arr[i];
        }
    }

    return true;
}

// Time Complexity: O(N*Sum)  Space:O(1)
int findPages(vector<int> &arr, int n, int m)
{
    if (m > n) // studens>Books (Each student gets atleat one book)
        return -1;

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    // Check for every possible value.
    for (int numPages = 1; numPages <= sum; numPages++)
    {
        if (isPossible(arr, n, m, numPages))
        {
            return numPages;
        }
    }

    return -1;
}

// Time Complexity:O(N log Sum)   Space:O(1)

int findPages1(vector<int> &arr, int n, int m)
{
    if (m > n) // studens>Books (Each student gets atleat one book)
        return -1;

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    int start = 0, end = sum;
    int ans = -1;

    // Check for every possible value.
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(arr, n, m, mid))
        {
            ans = mid; // need to find minima
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}
int main()
{

    return 0;
}