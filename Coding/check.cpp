#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    set<int> a = {1, 2, 3,4,5};
    set<int> b = {1, 2, 3, 4, 5};

    // Return value: True, if every element of 2nd container lies in 1st container.
    // It has linear time complexity.

    bool isProperSubset = includes(b.begin(), b.end(), a.begin(), a.end());

    if (isProperSubset) {
        std::cout << "Set a is a proper subset of set b." << std::endl;
    } else {
        std::cout << "Set a is not a proper subset of set b." << std::endl;
    }

    return 0;
}
