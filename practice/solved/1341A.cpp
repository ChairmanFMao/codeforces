#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    string out = (a+b)*n >= c-d && (a-b)*n <= c+d ? "Yes" : "No";
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
