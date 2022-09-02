#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Just root abritarily and greedy?
// Each leaf node will always be on one of its bounds
// I think dp would be needed for the very optimum solution
// Ended up looking at tutorial, its dp
// Tree dp, getting the max from each subtree and building up

const int mxN = 1e5;
ll bounds[mxN][2], dp[mxN][2];
vector<int> adj[mxN];

void dfs(int node, int parent) {
	dp[node][0] = dp[node][1] = 0;

	for (int u : adj[node]) {
		if (u == parent)
			continue;

		dfs(u, node);
		dp[node][0] += max(abs(bounds[node][0] - bounds[u][1]) + dp[u][1], abs(bounds[node][0] - bounds[u][0]) + dp[u][0]);
		dp[node][1] += max(abs(bounds[node][1] - bounds[u][1]) + dp[u][1], abs(bounds[node][1] - bounds[u][0]) + dp[u][0]);
	}
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> bounds[i][0] >> bounds[i][1];
		adj[i].clear();
	}

	for (int i = 0; i < n-1; i++) {
		int u,v; cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(0,-1);
	cout << max(dp[0][0], dp[0][1]) << "\n";
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

