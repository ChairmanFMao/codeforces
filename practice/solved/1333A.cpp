#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first try due to the space ;-;
// Accepted second try

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        if (i == n-1) {
            for (int j = 0; j < m; j++) {
                cout << 'B';
            }
            cout << "\n";
            return;
        }
        for (int j = 0; j < m; j++) {
            char out = j == m-1 ? 'B' : 'W';
            cout << out;
        }
        cout << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}