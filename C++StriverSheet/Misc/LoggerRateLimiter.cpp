#include <iostream>
#include <unordered_map>
using namespace std;

// Design a logger system that receives a stream of meassages along with their timestamp.

// Each unique message should only be printed at most every 10 seconds.(i.e. a measage printed at timestamp t will prevent other IDENTICAL MESSAGES from being printed until timestamp t+10)

// All meaasges will come in chronological order.
// Several messages may arrive at the same timestamp.

// Implement the logger class.

// Logger() initializes the logger object.

// bool shouldPrintMessage(int timestamp, string message) - Returns true if the message should be printed in the given timestamp, otherwise returns false.

// Approach: If incoming is not present in hashmap, then insert it into hashmap and return TRUE
// If present in hashamp, check the timestamp whether it is greater than or eqaul to t+10. If Yes, return true and update the timestamp, else return false.

class Logger
{
public:
    unordered_map<string, int> hmap; // string with time stamp
    Logger()
    {
    }

    bool shouldPrintMessage(int timestamp, string message)
    {
        if (hmap.count(message))
        {
            int oldTimestamp = hmap[message];
            if (timestamp >= oldTimestamp + 10)
            {
                hmap[message] = timestamp;
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            hmap[message] = timestamp;
            return true;
        }
    }
};
int main()
{

    return 0;
}