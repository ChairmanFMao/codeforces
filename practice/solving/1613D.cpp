
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// I had a think about this for a long time, not sure exactly how to do it
// Ended up looking at the solution, don't really fully understand all of it.
// Decided to not finish it, might try it again later

const ll mxN = 5e5, mod = 998244353;
ll n, out = 0;
vector<ll> numbers(mxN+1);
vector<bool> used(mxN+1, 0);

ll later(int node) {
    ll current = numbers[node];
    ll out = 0;
    for (int i = node+1; i < n; i++) {
        if (numbers[i] >= current) {
            current = numbers[i];
            out++;
            used[i] = 1;
        }
    }
    return out;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            out += 1 << later(i);
        }
    }

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
