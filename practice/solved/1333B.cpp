#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Accepted first try!

void solve() {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    
    set<int> before;
    for (int i = 0; i < n; i++) {
        if ((b[i] < a[i] && (before.count(-1) == 0)) || (b[i] > a[i] && (before.count(1) == 0))) {
            cout << "NO" << "\n";
            return;
        }
        before.insert(a[i]);
    }
    cout << "YES" << "\n";
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