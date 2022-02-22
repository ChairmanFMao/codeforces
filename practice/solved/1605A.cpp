
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Best case is when a[0] + a[2] == 2 * a[1]

void solve() {
    ll all = 0;
    for (int i = 0, a; i < 3; i++) {
        cin >> a;
        all += a;
    }
    cout << (all % 3 ? "1" : "0") << "\n";
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
