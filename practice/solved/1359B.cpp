#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Let's go, first try!

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    char row[m];
    int cost = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char tile;
            cin >> tile;
            row[j] = tile;
        }
        bool last = 0;
        for (int j = 0; j < m-1; j++) {
            if (row[j] == '.' && row[j+1] == '.' && y < x*2) {
                cost += y;
                j++;
                if (j == m-1)
                    last = 1;
            } else if (row[j] == '.')
                cost += x;
        }
        if (last == 0 && row[m-1] == '.')
            cost += x;
    }
    cout << cost << "\n";
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