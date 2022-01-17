#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first try due to bad time complexity
// Accepted second try

void solve() {
    int n, x;
    cin >> n >> x;
    if (n < 2) {
        cout << 1 << "\n";
        return;
    }
    int floor = ceil((double)(n-2)/x) + 1;
    cout << floor << "\n";
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