#include <bits/stdc++.h>
using namespace std;

// Looked at solution, it wasn't actually that hard but I just didn't think of the maths of the problem

void solve() {
    int n, k;
    cin >> n >> k;
    int out = (n/k) * k + min(n % k, k / 2);
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