#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Given the arrival and departure times of all trains that reach a railway station, the task is to find the minimum number of platforms required for the railway station so that no train waits.

// Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. In such cases, we need different platforms.

// Input: n = 6
// arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
// dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
// Output: 3

// Find max number of overlapping interval that can be possible at a given time and it will give the minimum number of platforms required.

// Approach 1: For each train, find numner of overlapping time & store that maximum.
// Time Complexity:O(N2) Space:O(1)

// Approach 2: Sort both arrival and departure time and mentione approach tols in alst lines

// Time:O(N LogN) Space:O(1)

int findPlatform(int arr[], int dep[], int n)
{
    int numberOfPlatforms = 0;

    int overlappingIntervals = 0;

    sort(arr, arr + n);

    sort(dep, dep + n);

    int x = 0;
    int y = 0;

    while (x < n && y < n)
    {
        if (dep[y] >= arr[x])
        {
            x++;
            overlappingIntervals++;
        }
        else
        {
            y++;
            overlappingIntervals--;
        }

        numberOfPlatforms = max(numberOfPlatforms, overlappingIntervals);
    }

    return numberOfPlatforms;
}

int main()
{

    return 0;
}

// Approach to find max number of overlappling intervals at a given point.

// The idea is to store coordinates in a new vector of pair mapped with characters ‘x’ and ‘y’, to identify coordinates.
// Sort the vector. {Combined conatins value sof x,y}
// Traverse the vector, if an x coordinate is encountered it means a new range is added, so update count and if y coordinate is encountered that means a range is subtracted.
// Update the value of count for every new coordinate and take maximum