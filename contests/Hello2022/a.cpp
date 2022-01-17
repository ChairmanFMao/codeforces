#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, k;
    cin >> n >> k;
    
    if (n == 1) {
        cout << (k == 1 ? "R" : ".") << "\n";
        return;
    }
    if (k > (n & 1 ? n+1 : n)/2) {
        cout << -1 << "\n";
        return;
    }
    string out[n];
    string placeholder = "";
    for (int i = 0; i < n; i++)
        placeholder += ".";
    for (int i = 0; i < n; i++)
        out[i] = placeholder;
    for (int i = 0; i < n && i/2 < k; i+=2) {
        out[i][i] = 'R';
    }
    for (string i : out)
        cout << i << "\n";
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