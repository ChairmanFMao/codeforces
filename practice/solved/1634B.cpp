
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Initally looks like dfs but, the conditions would lead that to timeout I think.
// Potentially work backwards from y towards x or x+3.
// I think you could determine it using parity of something, one input is odd, other even.
// Actually very happy that my solution worked :)

void solve() {
    ll n, x, y, odd = 0;
    cin >> n >> x >> y;
    vector<ll> a(n);
    for (ll& i : a) {
        cin >> i;
        odd ^= i & 1;
    }

    odd ^= y & 1;

    cout << ((x & 1) == odd ? "Alice" : "Bob") << "\n";
    
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}
