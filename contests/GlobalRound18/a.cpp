#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    ll heightSum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        heightSum += a;
    }
    if (heightSum % n != 0)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}