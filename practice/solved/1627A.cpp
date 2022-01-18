
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n,m,r,c;
    cin >> n >> m >> r >> c;

    string current = "";
    int moves = 3;
    for (int i = 0; i < n; i++) {
        cin >> current;
        for (int j = 0; j < (int)current.size(); j++)
            if (current[j] == 'B') {
                int state = 2;
                if (i+1 == r)
                    state--;
                if (j+1 == c)
                    state--;
                moves = min(moves,state);
            }
    }
    cout << (moves == 3 ? -1 : moves) << "\n";
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
