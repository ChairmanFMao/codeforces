#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Accepted first time! very pleased! However, due to the map, set and vector the program took 13.5MB of memory

void solve() {
    int n;
    cin >> n;
    map<int, int> numbers;
    set<int> keys;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        numbers[a]++;
        keys.insert(a);
    }
    vector<int> unique(keys.begin(), keys.end());
    int largest = 0;
    for (int i = 0; i < unique.size(); i++) {
        if (numbers[unique[i]] > largest)
            largest = numbers[unique[i]];
    }
    int distinct = unique.size()-1;
    if (largest > distinct) {
        distinct++;
        largest--;
    }
    int out = min(distinct, largest);
    cout << out << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}