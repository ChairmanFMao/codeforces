#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first try, WA test 2, bad algorithm
// Failed second try, WA test 3, didn't account for an edge case
// Accepted third try!
// Notes: need to do more edge case testing before submitting, leads to unnecessary loss of points.

void solve() {
    int n, x;
    cin >> n >> x;
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a & 1)
            odd++;
        else
            even++;
    }

    if (odd == 0 || (odd == n && ((x & 1) == 0))) {
        cout << "No" << "\n";
        return;
    }
    odd--;
    x--;
    while (x > 0) {
        if (even > 0) {
            x--;
            even--;
        } else if (odd > 1) {
            x -= 2;
            odd -= 2;
        } else {
            cout << "No" << "\n";
            return;
        }
    }
    cout << "Yes" << "\n";
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