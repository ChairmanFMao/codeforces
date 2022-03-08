

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Potentially working backwards from the last operation until grid filled
// Program currently works but takes up 4.7 gigs of memory ;-;
const ll MOD = 998244353, mxN = 2e5;
ll out = 0, total = 0, n = 0, m = 0;
vector<pair<int,int>> operations(mxN);
vector<vector<bool>> grid(mxN, vector<bool>(mxN, 0));
vector<bool> rows(mxN, 0), columns(mxN,0);

int update(int x, int y) {
    int out = 0;
    for (int i = 0; i < m; i++) {
        if (!grid[x][m]) {
            grid[x][m] = 1;
            total++;
            out = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!grid[i][y]) {
            grid[i][y] = 1;
            total++;
            out = 1;
        }
    }
    return out;
}

void solve() {
    total = 0;
    out = 0;
    int k, q;
    cin >> n >> m >> k >> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            grid[i][j] = 0;
    }
    for (int i = 0; i < q; i++)
        cin >> operations[i].first >> operations[i].second;
    
    for (int i = q-1; ~i && total < m*n; i--) {
        out += update(operations[i].first-1, operations[i].second-1);
    }

    ll power = 1;
    for (int i = 0; i < out; i++)
        power = (power * k) % MOD;

    cout << power << "\n";
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
