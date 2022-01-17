#include <bits/stdc++.h>
using namespace std;
#define ll long long

// WA test 1 on first try, I think my grid numbers are wrong
// WA test 1 on second try due to an extra \n
// WA test 1 on third try due to more formatting
// WA test 3 on fourth try, just a little bug
// Finally accepted on fifth try, need to be more careful

void solve() {
    bool grid[9];
    memset(grid, 1, 9);
    vector<vector<int>> numbers = {{0,1,3},{0,1,2,4},{1,2,5},{0,6,3,4},{3,5,1,4,7},{4,2,5,8},{7,6,3},{6,8,7,4},{8,7,5}};

    for (int i = 0; i < 9; i++) {
        int t;
        cin >> t;
        t %= 2;
        if (t > 0)
            for (int j = 0; j < numbers[i].size(); j++)
                grid[numbers[i][j]] ^= 1;
    }
    for (int i = 0; i < 9; i++) {
        if (i%3 == 0 && i != 0)
            cout << "\n";
        cout << grid[i];
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
