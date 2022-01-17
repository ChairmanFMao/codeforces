#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    string output = "";
    string sub = "";
    for (int i = 0; i < b; i++)
        sub += (char) (i + 97);
    for (int i = 0; output.length() < n; i++)
        output += sub;
    cout << output.substr(0,n) << "\n";
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