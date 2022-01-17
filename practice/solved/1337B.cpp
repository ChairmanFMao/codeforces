#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, n, m;
    cin >> x >> n >> m;
    for (int i = 0; i < n && x > 20; i++) {
        x /= 2;
        x += 10;
    }
    string win = x - (m * 10) <= 0 ? "YES" : "NO";
    cout << win << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve();
}