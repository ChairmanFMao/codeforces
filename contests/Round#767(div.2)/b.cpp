#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll l, r, k;
    cin >> l >> r >> k;

    if (l == r) {
        cout << (r == 1 ? "NO" : "YES") << "\n";
        return;
    }

    ll odd = (r-l+1)/2 + (l & 1 && r & 1 ? 1 : 0);

    if (k < odd) {
        cout << "NO\n";
    } else
        cout << "YES\n";
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
