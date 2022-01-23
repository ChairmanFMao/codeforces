
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Had a brute force solution but tle on test 3
// I think that binary search would be a good approach here
// Took a while wrestling with the code, I was altering some global variables

ll k, x;

ll calc(ll mid) {
   ll total = 0;
    if (mid >= k) {
        total += (k*k + k)/2;
        mid -= k;
        k--;
        total += (k*k+k)/2 - ((k-mid)*(k-mid) + (k-mid))/2;
        k++;
    } else {
        total += (mid*mid + mid)/2;
    }
    return total;
}

void solve() {
    cin >> k >> x;

    if (calc(k+k-1) <= x) {
        cout << k+k-1 << "\n";
        return;
    }
    
    ll lower = 1, upper = k+k-1, mid, best = 1e18;
    while (lower <= upper) {
        mid = (lower+upper)/2;
        if (x <= calc(mid)) {
            best = min(mid,best);
            upper = mid-1;
        } else
            lower = mid+1;
    }

    cout << best << "\n";
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
