#include <bits/stdc++.h>
using namespace std;

// This was very satisfying to solve

void solve() {
    long long x, y;
    cin >> x >> y;
    string out = x - y == 1 ? "NO" : "YES";
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