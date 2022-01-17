#include <bits/stdc++.h>
using namespace std;

// Had a solution that originally timed out, needed to optimise it by checking if
// n was even, and then adding 2 times what was left of k

int lowest(int n) {
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            return i;
        }
    }
    return 0;
}

void solve() {
    int n, k;
    cin >> n >> k;
    while (n%2 != 0) {
        n += lowest(n);
        k--;
    }
    n += 2 * k;
    cout << n << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve();
}