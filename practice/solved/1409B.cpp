#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Did a lot of thinking but it was accepted first try!

void solve() {
    ll a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    ll adif = a - x, bdif = b - y;
    ll acopy = a, bcopy = b, ncopy = n;
    if (n >= adif + bdif) {
        cout << x*y << "\n";
        return;
    }
    if (adif > 0) {
        a -= min(adif, n);
        n -= min(adif, n);
    } if (bdif > 0) {
        b -= min(bdif, n);
        bcopy -= min(bdif, ncopy);
        ncopy -= min(bdif, ncopy);
        n -= min(bdif, n);
    } if (adif > 0) {
        acopy -= min(adif, ncopy);
        ncopy -= min(adif, ncopy);
    }
    
    cout << min(a*b, acopy*bcopy) << "\n";
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