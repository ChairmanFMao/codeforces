#include <bits/stdc++.h>
using namespace std;

// Four in a row!

void solve() {
    int n;
    cin >> n;
    int prev = 0, count = 0;
    cin >> prev;
    bool good = 1;
    for (int i = 0; i < n-1; i++) {
        int a;
        cin >> a;
        if (prev <= a)
            good = 0;
        prev = a;
    }
    string out = good ? "NO" : "YES";
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