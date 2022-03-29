
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Potentially working backwards from the last operation until grid filled
// Program currently works but takes up 4.7 gigs of memory ;-;
// Optimised the program but, somehow gets TLE on test 7, memory is no longer a problem
// I changed the vectors of rows and columns to arrays and used memset to reset them
// this sped up my code enough to pass all of the tests!
const ll MOD = 998244353, mxN = 2e5;
ll out = 0, rowsD = 0, columnsD = 0, n = 0, m = 0;
vector<pair<int,int>> operations(mxN);
bool rows[mxN], columns[mxN];

int update(int x, int y) {
    int out = 0;
    if (rowsD != n) {
        if (!rows[x]) {
            out = 1;
            rows[x] = 1;
            rowsD++;
        }
    } if (columnsD != m) {
        if (!columns[y]) {
            out = 1;
            columns[y] = 1;
            columnsD++;
        }
    }
    return out;
}

void solve() {
    out = rowsD = columnsD = 0;
    ll k, q;
    cin >> n >> m >> k >> q;
    memset(columns, 0, sizeof columns);
    memset(rows, 0, sizeof rows);
    for (int i = 0; i < q; i++)
        cin >> operations[i].first >> operations[i].second;
    
    for (int i = q-1; ~i && (m != columnsD && n != rowsD); i--) {
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
