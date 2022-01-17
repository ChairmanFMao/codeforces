#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Accepted first try!

void solve() {
    int x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

    int score = 0;
    int z1y2 = min(z1, y2);
    score += 2 * z1y2;
    z1 -= z1y2;
    y2 -= z1y2;
    
    int x1z2 = min(x1, z2);
    z2 -= x1z2;
    x1 -= x1z2;

    int z1z2 = min(z1, z2);
    z1 -= z1z2;
    z2 -= z1z2;

    score -= 2 * min(z2, y1);

    cout << score << "\n";
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