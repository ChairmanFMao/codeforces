#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c <= d && a > b) {
        cout << -1 << "\n";
        return;
    }
    long long minutes = 0;
    minutes += b;
    a -= b;
    // Always try to use linear time rather than a while loop with linear time
    if (a > 0) {
        double cycles = (double) a / (c - d);
        minutes += ceil(cycles) * c;
    }
    cout << minutes << "\n";
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