#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int twoPow = 1;
    for (int i = 2; twoPow < n; i*=2) {
        twoPow += i;
        if (n % twoPow == 0) {
            cout << n/twoPow << "\n";
            return;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve();
    }
}