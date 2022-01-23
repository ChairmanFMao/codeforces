
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int x, y;
    cin >> x >> y;
    
    if ((x+y) & 1) {
        cout << "-1 -1\n";
        return;
    }

    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if (i + j == (x+y)/2 && abs(i-x) + abs(j-y) == (x+y)/2) {
                cout << i << " " << j << "\n";
                return;
            }
        }
    }
    cout << "-1 -1\n";
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
