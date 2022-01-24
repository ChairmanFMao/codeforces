
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// The solution works, but it just times out with big inputs, as the dfs for each node is too slow
// Rewrote all my code after looking at solution, not entirely sure how to apply dp, but I'll figure it out.
// Came back to this problem a lot later, still not really sure how to do it...

const ll mxK = 5e4;
ll n, k, out;
vector<vector<ll>> adj(mxK+1);
vector<vector<ll>> dp(mxK+1, vector<ll>(mxK+1));

void dfs(ll prev, ll current, ll depth, ll original) {
    dp[original][depth]++;
    for (ll next : adj[current])
        if (next != prev)
            dfs(current, next, depth+1, original);
}

void solve() {
    out = 0;
    cin >> n >> k;
    for (ll i = 0,a,b; i < n-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // Resets all of the dp vector
    for (ll i =0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = 0;
    
    // Calculates the count of values that are a certain distance from the original node
    for (int i = 1; i <= n; i++) {
        dp[i][0]--;
        dfs(0,i,0,i);
    }
    
    for (int i = 1; i <= n; i++) {
        out += dp[i][k];
        ll subtotal = 0;
        for (int j = 0; j < (int)dp[i].size(); j++) {
            for (int m = 1; m < k; m++) {
                subtotal += dp[j][m-1] * (dp[i][k-m] - dp[j][k-m-1]);
            }
        }
        out += subtotal >> 1;
    }
        
    cout << out << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
