#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first try, WA test 1
// Failed second try, WA test 2
// Failed third try, WA test 3, was just extending original code to cope with edge cases, don't think that it has helped.
// Accepted fourth try! It actually was just an edge case that I wasn't accounting for ;-;

void solve() {
    int n, k;
    cin >> n >> k;

    if (k > n || ((n & 1) && (k & 1) == 0) || (k*2>n && (n&1) != (k&1))) {
        cout << "NO" << "\n";
        return;
    }
    cout << "YES" << "\n";
    int number = (n & 1) || n == k ? 1 : 2;
    if ((n&1) == 0 && (k&1) == 0 && k*2>n && k != n)
        number = 1;
    while (k > 1) {
        cout << number << " ";
        k--;
        n -= number;
    }
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