#include <bits/stdc++.h>
using namespace std;
#define ll long long

// First try!

void solve() {
    int a, b, n, s;
    cin >> a >> b >> n >> s;
    int x = s / n;
    if (x > a)
        x = a;
    string out = (x*n+b) >= s ? "YES" : "NO";
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