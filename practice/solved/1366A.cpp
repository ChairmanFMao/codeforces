#include <bits/stdc++.h>
using namespace std;
#define ll long long

// First try on computer got WA on second test
// Accepted second try!

void solve() {
    int a, b;
    cin >> a >> b;
    int emeralds = 0, difference = abs(a-b), abig = a > b;
    if (a > b) {
        emeralds += difference;
        a -= 2 * difference;
        b -= difference;
    } else if (b > a) {
        emeralds += difference;
        b -= 2 * difference;
        a -= difference;
    }
    if (abig && a < 0) {
        emeralds += a;
        a = 0;
    } if (!abig && b < 0) {
        emeralds += b;
        b = 0;
    }
    if (a > 0 && b > 0) {
        emeralds += (a/3)*2;
        a %= 3;
        b %= 3;
    }
    if ((a > 0 && b > 1) || (b > 0 && a > 1))
        emeralds++;
    cout << emeralds << "\n";
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