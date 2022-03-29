
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 2 n^2 cap for operations must be important
// There must be an even number of each number for valid input

void solve() {
    int n;
    cin >> n;
    map<int,queue<int>> occurs;
    set<int> unique;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        occurs[numbers[i]].push(i);
        unique.insert(numbers[i]);
    }
    
    // Detects if the array is valid or not
    vector<int> uniqueV(unique.begin(),unique.end());
    for (int i : uniqueV)
        if ((int)occurs[i].size() & 1) {
            cout << -1 << "\n";
            return;
        }
    
    // Misunderstood the problem, numbers can only be inserted in pairs
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
