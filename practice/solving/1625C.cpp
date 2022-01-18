#include <bits/stdc++.h>
using namespace std;
#define ll long long

// What if there is a vector for each point and there is vector of pairs for the number of removals
// I have an error somewhere and it's not integer overflow
// Keeps screwing up on test case 8, idk what the issue is as the code works fine for other tests

const int mxN = 500;
const ll INF = 1000000000000000ll;
// Vector for all of the points, map for the number of removals done
vector<map<ll,vector<ll>>> dp(mxN+1);

void solve() {
    ll n, l, k;
    cin >> n >> l >> k;
    ll coords[n+1], limit[n];
    for (int i = 0; i < n; i++)
        cin >> coords[i];
    for (int i = 0; i < n; i++)
        cin >> limit[i];
    coords[n] = l;

    vector<ll> fill;
    fill.push_back(INF);
    fill.push_back(INF);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++)
            dp[i][j] = fill;
    }
    
    // This is here as the first sign can't be removed
    vector<ll> start;
    start.push_back(limit[0]*coords[1]);
    start.push_back(limit[0]);
    dp[1][0] = start;
    for (int i = 1; i < n; i++) {
        // This goes over all of the possible choices that could've been made
        for (int j = 0; j < (int) dp[i].size(); j++) {
            // This is to skip the current road sign
            if (j < k) {
                vector<ll> next;
                next.push_back(dp[i][j][0] + (coords[i+1]-coords[i])*dp[i][j][1]);
                next.push_back(dp[i][j][1]);
                if (next[0] < dp[i+1][j+1][0])
                    dp[i+1][j+1] = next;
            }
            // This is to not skip the current sign
            vector<ll> otherNext;
            otherNext.push_back(dp[i][j][0] + (coords[i+1]-coords[i])*limit[i]);
            otherNext.push_back(limit[i]);
            if (otherNext[0] < dp[i+1][j][0])
                dp[i+1][j] = otherNext;
        }
    }

    // This iterates over all of the totals for every number of signs removed, getting the lowest
    ll out = INF;
    for (int i = 0; i <= k; i++)
        out = min(out, dp[n][i][0]);
    cout << out << "\n";
}

int main(void) {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    solve();
}
