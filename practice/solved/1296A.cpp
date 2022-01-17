#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    set<int> parity;
    int all = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (parity.count(a & 1) == 0)
            parity.insert(a & 1);
        all += a & 1;
        all &= 1;
    }
    string out = parity.size() == 2 || all == 1 ? "YES" : "NO";
    cout << out << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}