#include <bits/stdc++.h>
using namespace std;
#define ll long long

// What if there is a vector for each point and there is vector of pairs for the number of removals
// I have an error somewhere and it's not integer overflow
// Keeps screwing up on test case 8, idk what the issue is as the code works fine for other tests
// Basically, some states that have lower speed and larger time are better than states with higher speed and lower time
// Need to make it consider these states, time complexity should go to O(n^3)
// Mainly just copied of tourist

void solve() {
    ll n, l, k;
    cin >> n >> l >> k;
    ll coords[n+1], limit[n];
    for (int i = 0; i < n; i++)
        cin >> coords[i];
    for (int i = 0; i < n; i++)
        cin >> limit[i];
    coords[n] = l;

    // Sets up the dp to be ready with all initally infinity
    vector<vector<ll>> dp(n+1, vector<ll>(k+1,(ll)1e18));

    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        // This goes over all of the possible choices that could've been made
        for (int j = 0; j <= k; j++) {
            for (int m = i-1; m >= 0; m--) {
                // This is the number of signs remaining
                int prevj = j - (i-m-1);
                // This line ensure that the limit of k is not passed
                if (prevj >= 0) {
                    dp[i][j] = min(dp[i][j], dp[m][prevj] + (coords[i]-coords[m]) * limit[m]);
                }
            }
        }
    }

    // This iterates over all of the totals for every number of signs removed, getting the lowest
    ll out = (ll)1e18;
    for (int i = 0; i <= k; i++)
        out = min(out, dp[n][i]);
    
    cout << out << "\n";
}

int main(void) {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    solve();
}