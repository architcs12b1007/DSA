#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct Computer {
    int power;
    int frequency;
};

bool sortByPower(const Computer& a, const Computer& b) {
    return a.power > b.power;
}

int calculateServerRating(const vector<Computer>& computers, const vector<int>& combination) {
    int totalPower = 0;
    int versatility = 0;
    unordered_set<int> uniqueFrequencies;

    for (int index : combination) {
        totalPower += computers[index].power;
        uniqueFrequencies.insert(computers[index].frequency);
    }

    versatility = uniqueFrequencies.size();

    return totalPower + versatility * versatility;
}

void generateCombinations(const vector<Computer>& computers, vector<int>& combination, int index, int m, int& maxServerRating) {
    if (combination.size() == m) {
        int serverRating = calculateServerRating(computers, combination);
        maxServerRating = max(maxServerRating, serverRating);
        return;
    }

    if (index >= computers.size())
        return;

    // Include the current computer in the combination
    combination.push_back(index);
    generateCombinations(computers, combination, index + 1, m, maxServerRating);
    combination.pop_back();

    // Skip the current computer and move to the next one
    generateCombinations(computers, combination, index + 1, m, maxServerRating);
}

int main() {
    int n;
    cin >> n;

    vector<Computer> computers(n);
    for (int i = 0; i < n; i++) {
        cin >> computers[i].power;
    }

    for (int i = 0; i < n; i++) {
        cin >> computers[i].frequency;
    }

    int m;
    cin >> m;

    sort(computers.begin(), computers.end(), sortByPower);

    vector<int> combination;
    int maxServerRating = 0;
    generateCombinations(computers, combination, 0, m, maxServerRating);

    cout << maxServerRating << endl;

    return 0;
}
