#include <bits/stdc++.h>
using namespace std;
#define ll long long

// WA test 2 first try

void solve() {
    int l1,l2,l3;
    cin >> l1 >> l2 >> l3;
    int sum = l1 + l2 + l3;
    int same = 0;
    if (l1 == l2 || l1 == l3)
        same = l1;
    if (l2 == l3)
        same = l3;
    if (sum % 2) {
        cout << "NO\n";
        return;
    }
    if (same != 0) {
        if ((sum - same - same) % 2 == 0) {
            cout << "YES\n";
            return;
        }
    }
    if (sum - max(l1,max(l2,l3)) == sum/2) {
        cout << "YES\n";
        return;
    }
    else
        cout << "NO\n";
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