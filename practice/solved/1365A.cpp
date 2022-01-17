#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Accepted first try!

void solve() {
    int n, m;
    cin >> n >> m;
    int numbers[n][m], rows = 0, columns = 0;
    for (int i = 0; i < n; i++) {
        bool row = 0;
        for (int j = 0; j < m; j++) {
            cin >> numbers[i][j];
            if (numbers[i][j])
                row = 1;
        }
        if (!row)
            rows++;
    }
    for (int i = 0; i < m; i++) {
        bool col = 0;
        for (int j = 0; j < n; j++) {
            if (numbers[j][i])
                col = 1;
        }
        if (!col)
            columns++;
    }
    int moves = min(rows,columns);
    string out = moves & 1 ? "Ashish" : "Vivek";
    cout << out << "\n";
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