#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;

    string scopy = s, tcopy = t;
    sort(scopy.begin(), scopy.end());
    sort(tcopy.begin(), tcopy.end());
    // This accounts for the case when it is not possible to make s smaller than t
    if (s >= t) {
        cout << -1 << "\n";
        return;
    }
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