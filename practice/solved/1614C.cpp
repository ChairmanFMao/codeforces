
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 1e9 + 7;

// Looked at solution because I kinda had no idea what to do
// Basically, you needed to make a clever observation, that I didn't see
// The problem is actually quite nice if you think about it

void solve() {
    ll n, m;
    cin >> n >> m;
    
    ll x = 0;
    for (int i = 0,l,r,a; i < m; i++) {
        cin >> l >> r >> a;
        x |= a;
    }
    x %= mod;
    ll number = 1;
    for (int i = 0; i < n-1; i++)
        number = (number * 2)%mod;
    cout << (x * number) % mod << "\n";
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
