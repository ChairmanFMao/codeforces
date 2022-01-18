
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// The solution works, but it just times out with big inputs, as the dfs for each node is too slow
// Rewrote all my code after looking at solution, not entirely sure how to apply dp, but I'll figure it out.

const ll mxK = 5e4;
ll n, k, pairs = 0;
vector<vector<ll>> adj(mxK+1);
vector<vector<ll>> dist(mxK+1, vector<ll>(mxK+1));
vector<vector<ll>> dp(mxK+1, vector<ll>(mxK+1));

void solve() {
    cin >> n >> k;
    for (ll i = 0,a,b; i < n-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for (int i = 1; i<=n; i++) {
        
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
