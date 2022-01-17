#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Took all of the logic from Neal wu's solution

void solve() {
    int n;
    cin >> n;
    vector<ll> appear(n), health(n);
    for (ll i = 0; i < n; i++)
        cin >> appear[i];
    for (ll i = 0; i < n; i++)
        cin >> health[i];

    // somehow we are using dynamic programming
    ll dp[n+1];
    for (int i = 0; i <= n; i++)
        dp[i] = (ll) 1e20;
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = i; k < n; k++) {
                if (health[j] - appear[j] + appear[k] < health[k])
                    break;
                
                if (k >= j) {
                    ll current = health[j] - appear[j] + appear[k];
                    if (!i || appear[k] - current >= appear[i-1])
                        dp[k+1] = min(dp[k+1], dp[i] + (current * (current+1))/2);
                }
            }
        }
    }
    cout << dp[n] << "\n";
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