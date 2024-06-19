#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// There are N petrol pumps on a circle. You will be given two sets of data.
// 1. The amount of petrol that every petrol pump has.
// 2. Distance from that petrol pump to the next petrol pump.
// Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
// Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

// Approach 1: Brute force: Check for each petrol pump:O(N2)

// Approach 2: Keep track of deficitPetrol and surplusPetrol while traversing through pertrol pumps.
// If at the end, surplus petrol is more, then return front petrolpump otherwise -1;

// Time Complexity:O(N) Space Complexity:O(1)

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[], int n)
{
    int front = 0, rear = 0;
    int surplusPetrol = 0;
    int deficitPetrol = 0;

    while (rear < n)
    {
        surplusPetrol += p[rear].petrol - p[rear].distance;
        if (surplusPetrol >= 0)
        {
            rear++;
        }
        else

        {
            front = rear + 1;
            rear = front;

            deficitPetrol += surplusPetrol;
            surplusPetrol = 0;
        }
    }

    if (front != n && surplusPetrol + deficitPetrol >= 0)
    {
        return front;
    }
    else
    {
        return -1;
    }
}

// simplified

int tour1(petrolPump p[], int n)
{
    int surplus = 0, deficit = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        surplus += p[i].petrol - p[i].distance;
        if (surplus < 0)
        {
            deficit += surplus;
            surplus = 0;
            start = i + 1;
        }
    }

    if (surplus + deficit >= 0)
        return start;
    else
        return -1;
}
int main()
{

    return 0;
}
