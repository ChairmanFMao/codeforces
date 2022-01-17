#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a;
    cin >> a;
    int parity = a % 2;
    bool good = 1;
    for (int i = 0; i < n - 1; i++) {
        int b;
        cin >> b;
        if (b % 2 != parity)
            good = 0;
    }
    string out = good ? "YES" : "NO";
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