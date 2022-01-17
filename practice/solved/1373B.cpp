#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int ones = 0, zeros = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0')
            zeros++;
        else
            ones++;
    }
    string out = min(zeros,ones) % 2 == 1 ? "DA" : "NET";
    cout << out << "\n";
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