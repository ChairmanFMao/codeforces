#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << -1 << "\n";
        return;
    }
    string out = "2";
    for (int i = 0; i < n-1; i++) {
        out += "3";
    }
    cout << out << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve();
    }
}