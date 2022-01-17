#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Took a while thinking but solved it first try

void solve() {
    ll x, n;
    cin >> x >> n;
    ll mod = n%4;
    n -= mod;
    for (int i = 1; i <= mod; i++) {
        if (x & 1)
            x += n + i;
        else
            x -= n + i;
    }
    cout << x << "\n";
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