
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// I had to look at the solution, kinda stuck when I first saw the problem
// Took a little while to get my head around the problem statement.
// Did end up eventually looking at the solution, very nice maths

void solve() {
    ll n;
    cin >> n;
    
    ll total = 0;
    vector<ll> b(n), a(n);
    for (ll&i : b) {
        cin >> i;
        total += i;
    }

    // Total must be divisible by this as in the sum of all of the durations
    // a[i] each occurs n*n+n / 2 times in the total, so the total must be
    // divisible by this.
    if (total % ((n*n + n) / 2)) {
        cout << "NO\n";
        return;
    }
    
    // This is the sum of all the a[i]
    total /= (n*n + n)/2;
    
    for (ll i = 0; i < n; i++) {
        if ((total - (b[(i+1)%n] - b[i])) % n) {
            cout << "NO\n";
            return;
        }
        a[i] = (total - (b[(i+1)%n] - b[i]))/n;
        if (a[i] <= 0) {
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES\n";
    for (ll i = n-1; i < 2*n-1; i++)
        cout << a[i%n] << " ";
    cout << "\n";
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
