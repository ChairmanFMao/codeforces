
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    vector<int> valid;
    for (int i = 0,a; i < n; i++) {
        cin >> a;
        if (a >= l && a <= r)
            valid.push_back(a);
    }

    int bars = 0;
    sort(valid.begin(),valid.end());
    for (int i = 0; i < (int) valid.size(); i++) {
        if (k >= valid[i]) {
            k -= valid[i];
            bars++;
        }
    }

    cout << bars << "\n";
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
