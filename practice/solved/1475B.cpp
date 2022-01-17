#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i * 2020 <= n; i++) {
        for (int j = 0; j * 2021 + i * 2020 <= n; j++) {
            if (j * 2021 + i * 2020 == n) {
                cout << "YES" << "\n";
                return;
            }
        }
    }
    cout << "NO" << "\n";
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