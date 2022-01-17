#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Looked at the solution because kinda dumbfounded, maybe I need to do more strings
// Failed first time due to bad code
// Accepted second try!

void solve() {
    string t;
    cin >> t;
    char first = t[0];
    bool same = 1;
    for (int i = 0; i < t.length(); i++) {
        if (t[i] != first)
            same = 0;
    }
    if (same) {
        cout << t << "\n";
        return;
    }
    string add = "";
    add += first;
    add += (first == '0' ? '1' : '0');
    string out = "";
    while (out.length() < (t.length() * 2) - 2)
        out += add;
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