#include <bits/stdc++.h>
using namespace std;

// 5th!!!!!!!

void solve() {
    int n, k;
    cin >> n >> k;
    int f, t;
    cin >> f >> t;
    int maxJoy = t > k ? f - (t - k) : f;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        maxJoy = max(maxJoy, (b > k ? a - (b - k) : a));
    }
    cout << maxJoy << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    solve();
}