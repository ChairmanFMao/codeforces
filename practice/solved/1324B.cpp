#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first try WA on test 13 this was due to a typo
// Second try failed, WA on test 14, turns out I misunderstood the problem
// Accepted third try after I redesigned the algorithm

void solve() {
    int n;
    cin >> n;
    int numbers[n];
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    
    map<int, int> positions;
    for (int i = 0; i < n; i++)
        positions[numbers[i]] = 0;
    for (int i = 0; i < n; i++) {
        if (positions[numbers[i]] == 0)
            positions[numbers[i]] = i+1;
        else if (positions[numbers[i]] != i) {
            cout << "YES" << "\n";
            return;
        }
    }
    cout << "NO" << "\n";
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