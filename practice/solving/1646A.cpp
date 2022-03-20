
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, s;
    cin >> n >> s;
    cout << s/(n*n) << "\n";
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
