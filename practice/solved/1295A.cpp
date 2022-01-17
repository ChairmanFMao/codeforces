#include <bits/stdc++.h>
using namespace std;

// This was super fast!

void solve() {
    int n;
    cin >> n;
    string out = "";
    if (n & 1) {
        out += '7';
        n -= 3;
    }
    for (int i = n; i > 0; i-=2)
        out += "1";
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