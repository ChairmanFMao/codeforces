#include <bits/stdc++.h>
using namespace std;

// Looked at tutorial, if n is less than k we have to move A to k
// If n >= k if the parity of n and k are the same 0 otherwise 1

void solve() {
    int n, k;
    cin >> n >> k;
    if (n < k) {
        cout << k-n << "\n";
    } else {
        int out = n%2 != k%2;
        cout << out << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}