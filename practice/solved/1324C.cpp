#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first try, WA test 1, algorithm just bad
// Epicly accepted second try!

void solve() {
    string s;
    cin >> s;
    int longest = 1, current = 1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != 'R')
            current++;
        else {
            longest = max(longest,current);
            current = 1;
        }
    }
    longest = max(longest,current);
    cout << longest << "\n";
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