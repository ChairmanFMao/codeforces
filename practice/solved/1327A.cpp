#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Wrong answer on first submission
// Accepted second try due to overlooking the fact that k*k could be larger than n

void solve() {
    ll n, k;
    cin >> n >> k;
    string out = ((k % 2 == 1) && (n % 2 == 0)) || ((k % 2 == 0) && (n % 2 == 1)) || (n < k*k) ? "NO" : "YES";
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