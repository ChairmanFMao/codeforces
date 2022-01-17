#include <bits/stdc++.h>
using namespace std;

int main(void) {
    vector<int> houses;
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        int x;
        cin >> x;
        houses.push_back(x);
    }
    sort(houses.begin(), houses.end());
    int moves = houses[2] - houses[0];
    cout << moves << "\n";
}