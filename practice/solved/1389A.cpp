#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Naive O(n^2) solution timed out, leading to failure on first submission
// Attempting to think of a more efficient algorithm
// Looked at solution because I wanted to go to bed and couldn't find answer
// x has to not be a divisor of y
// Accepted second try!

void solve() {
    ll l, r;
    cin >> l >> r;
    
    if (2*l > r)
        cout << "-1 -1\n";
    else
        cout << l << " " << 2*l << "\n";
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