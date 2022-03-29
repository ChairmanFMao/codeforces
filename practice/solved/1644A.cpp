
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    string s;
    cin >> s;
    bool r = 0, g = 0, b = 0;
    for (char c : s) {
        if (c == 'r')
            r = 1;
        if (c == 'b')
            b = 1;
        if (c == 'g')
            g = 1;
        if ((c == 'R' && !r) || (c == 'G' && !g) || (c == 'B' && !b)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
