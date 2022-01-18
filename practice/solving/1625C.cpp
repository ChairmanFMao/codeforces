#include <bits/stdc++.h>
using namespace std;
#define ll long long

// What if there is a vector for each point and there is vector of pairs for the number of removals
// I have an error somewhere and it's not integer overflow
// Keeps screwing up on test case 8, idk what the issue is as the code works fine for other tests
// Basically, some states that have lower speed and larger time are better than states with higher speed and lower time
// Need to make it consider these states, time complexity should go to O(n^3)

const int mxN = 500;
const ll INF = 1000000000000000ll;
// Vector for all of the points, map for the number of removals done
vector<map<ll,pair<ll,ll>>> dp(mxN+1);

void solve() {
    ll n, l, k;
    cin >> n >> l >> k;
    ll coords[n+1], limit[n];
    for (int i = 0; i < n; i++)
        cin >> coords[i];
    for (int i = 0; i < n; i++)
        cin >> limit[i];
    coords[n] = l;

    // This initally sets the distance to every state to infinity
    pair<ll,ll> fill = {INF,INF};
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = fill;
    
    // This is here as the first sign can't be removed
    dp[0][0] = {0,limit[0]};
    for (int i = 0; i < n; i++) {
        // This goes over all of the possible choices that could've been made
        for (int j = 0; j <= k; j++) {
            // This is to skip the current road sign
            if (j < k) {
                if (dp[i][j].first + (coords[i+1]-coords[i])*dp[i][j].second < dp[i+1][j+1].first)
                    dp[i+1][j+1] = {dp[i][j].first + (coords[i+1]-coords[i])*dp[i][j].second,dp[i][j].second};
            }
            // This is to not skip the current sign
            if (dp[i][j].first + (coords[i+1]-coords[i])*limit[i] < dp[i+1][j].first)
                dp[i+1][j] = {dp[i][j].first + (coords[i+1]-coords[i])*limit[i],limit[i]};
        }
    }

    // This iterates over all of the totals for every number of signs removed, getting the lowest
    ll out = INF;
    for (int i = 0; i <= k; i++)
        out = min(out, dp[n][i].first);
    
    std::cout << out << "\n";
}

int main(void) {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    solve();
}