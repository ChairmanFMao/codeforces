#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    string s;
    cin >> s;

    if (s.size() & 1) {
        cout << "NO" << "\n";
        return;
    }
    if (s.substr(0,s.size()/2) == s.substr(s.size()/2)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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