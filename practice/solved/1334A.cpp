#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first try, WA test 2, just an edge case that I wasn't accounting for
// Accepted second try!

void solve() {
    int n;
    cin >> n;

    int p, c;
    cin >> p >> c;
    bool bad = 0;
    if (p < c)
        bad = 1;
    
    for (int i = 1; i < n; i++) {
        int currentP, currentC;
        cin >> currentP >> currentC;
        if (currentP < p || currentC < c || currentP < currentC || currentP - p < currentC - c)
            bad = 1;
        p = currentP;
        c = currentC;
    }
    string out = bad ? "NO" : "YES";
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