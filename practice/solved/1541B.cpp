#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Brute force is not really an option here as it would just take too long
// Failed first time, WA test 3, just an annoying edge case
// Failed secon time, WA test 3, same error
// Accepted third time, turns out it was just due to integer overflow and I needed to store everything as longs to make this error dissappear

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll,ll>> pairs(n);
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        pairs[i] = {a, i+1};
    }
    
    sort(pairs.begin(), pairs.end());
    int good = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n && pairs[i].first*pairs[j].first <= 2*n; j++) {
            if (pairs[i].first*pairs[j].first == pairs[i].second+pairs[j].second)
                good++;
        }
    }
    cout << good << "\n";
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