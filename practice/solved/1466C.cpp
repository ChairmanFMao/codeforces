#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Epicly accepted first try!

void solve() {
    string s;
    cin >> s;

    int changes = 0;
    for (int i = 0; i < s.size()-1; i++) {
        if (i == 0) {
            if (s[i] == s[i+1]) {
                s[i+1] = ' ';
                changes++;
            }
            continue;
        }
        if (s[i] == s[i+1] || s[i-1] == s[i+1]) {
            s[i+1] = ' ';
            changes++;
        }
    }

    cout << changes << "\n";
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