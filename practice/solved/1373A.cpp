#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first time due to not using long long, integer overflow
// Accepted second time

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll firstCheap = a < c ? 1 : -1;
    ll lastCheap = b * a > c ? b : -1;
    cout << firstCheap << " " << lastCheap << "\n";
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