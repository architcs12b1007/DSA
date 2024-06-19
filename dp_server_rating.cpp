#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cstring>

using namespace std;

struct Computer {
    int power;
    int frequency;
};

bool sortByPower(const Computer& a, const Computer& b) {
    return a.power > b.power;
}

int memo[101][101];

int calculateServerRating(const vector<Computer>& computers, int n, int m, int totalPower, int versatility) {
    if (m == 0)
        return totalPower + versatility * versatility;

    if (n == 0)
        return 0;

    if (memo[n][m] != -1)
        return memo[n][m];

    int includeRating = calculateServerRating(computers, n - 1, m - 1, totalPower + computers[n - 1].power, versatility + (computers[n - 1].frequency == computers[n - 2].frequency ? 0 : 1));
    int excludeRating = calculateServerRating(computers, n - 1, m, totalPower, versatility);

    memo[n][m] = max(includeRating, excludeRating);
    return memo[n][m];
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

    memset(memo, -1, sizeof(memo));

    int maxServerRating = calculateServerRating(computers, n, m, 0, 0);

    cout << maxServerRating << endl;

    return 0;
}
