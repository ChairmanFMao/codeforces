#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ones = 0, zeros = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0')
            zeros++;
        else
            ones++;
    }
    cout << n - 2 * min(ones, zeros);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}