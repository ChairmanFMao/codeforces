#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;
    if (b == 1) {
        cout << "NO" << "\n";
        return;
    }
    long long x, y, z;
    x = a;
    z = a * a * b;
    y = z - x;
    // This is to take care of the edge case a = 1, b = 2
    if (x == y) {
        x *= 2;
        y *= 2;
        z *= 2;
        x += a;
        y -= a;
    }
    if (x <= 0 || y <= 0) {
        cout << "NO" << "\n";
        return;
    }
    cout << "YES" << "\n";
    cout << x << " " << y << " " << z << "\n";
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