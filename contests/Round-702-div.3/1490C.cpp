#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Timed out first try :(
// Completed second try with linear time rather than original O(n^2) time

void solve() {
    ll x;
    cin >> x;
    for (ll i = 1; i*i*i < x; i++) {
        ll other = round(pow(x - i*i*i, (double)1/3));
        if (other*other*other == x - i*i*i) {
            cout << "YES" << "\n";
            return;
        }
    }
    cout << "NO" << "\n";
    return;
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