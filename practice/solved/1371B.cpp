#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Unsure of how to proceed at the start of the problem
// Ended up looking at the solution
// It is done using funny maths "well-known formula" (a+b)*(b-a+1)/2
// Accepted first try

void solve() {
    ll n, l = 1, r, extra = 0;
    cin >> n >> r;

    if (n <= l) {
        cout << "1" << "\n";
        return;
    } if (n <= r) {
        r = n-1;
        extra = 1;
    }
    cout << extra+(l+r)*(r-l+1)/2 << "\n";
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