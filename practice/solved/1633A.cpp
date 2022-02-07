
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    if (!(n%7)) {
        cout << n << "\n";
        return;
    }
    n -= n % 10;
    while (n%7)
        n++;
    cout << n << "\n";
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
