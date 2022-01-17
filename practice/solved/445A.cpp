#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first try, WA test 2, stupid mistake
// Accepted second try!

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> board;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        board.push_back(a);
    }

    for (int i = 0; i < n; i++) {
        string out = "";
        for (int j = 0; j < m; j++)
            out += board[i][j] == '-' ? '-' : (j & 1) == (i & 1) ? 'W' : 'B';
        cout << out << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}