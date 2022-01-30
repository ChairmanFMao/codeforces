#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int dr = 1, dc = 1;
    int moves = 0;
    bool first = 1;
    while (1) {
        if (rb == rd || cb == cd) {
            cout << moves << "\n";
            return;
        }
        if (rb == n || rb == 1 && !first)
            dr *= -1;
        if (cb == m || cb == 1 && !first)
            dc *= -1;
        rb += dr;
        cb += dc;
        moves++;
        first = 0;
    }
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