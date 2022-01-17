#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, i, j;
    cin >> n >> m >> i >> j;
    // If in the top right or bottom left quadrant, so we use the bottom right and top left points
    if (i > n/2 && j > m/2 || i < n/2 && j < m/2) {
        cout << 1 << " " << m << " " << n << " " << 1 << "\n"; 
    } else {
        // Otherwise the point is in the bottom right or top left quadrant, so we use the top right and bottom left points
        cout << 1 << " " << 1 << " " << n << " " << m << "\n";
    }
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