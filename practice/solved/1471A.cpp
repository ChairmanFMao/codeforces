#include <bits/stdc++.h>
using namespace std;

// Only worked on the third try because I didn't use long long and had some issues with casting to double

void solve() {
    int n, x;
    cin >> n >> x;
    long long max = 0, min = 0, going = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        going += a;
        if (going % x == 0) {
            min += going / x + ((going % x == 0) ? 0 : 1);
            going = 0;
        }
        max += a / x + ((a % x == 0) ? 0 : 1);
    }
    min += going / x + ((going % x == 0) ? 0 : 1);
    cout << min << " " << max << "\n";
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