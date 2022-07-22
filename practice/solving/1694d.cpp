#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// C must be increasing
// Unsure where you would ever want to use the lower bound
const int mxN = 2e5;
vector<vector<ll> > adj(mxN);
vector<pair<ll,ll> > cap(mxN);
ll dp[mxN];
ll operations = 0;

void dfs(int node) {
	for (int i : adj[node])
		dfs(i);

	if (sz(adj[node]) == 0) {
		dp[node] = cap[node].second;
		operations++;
	} else {
		ll subtotal = 0;
		for (int i : adj[node])
			subtotal += dp[i];
		subtotal = min(subtotal, cap[node].second);
		if (subtotal >= cap[node].first)
			dp[node] = subtotal;
		else {
			dp[node] = cap[node].second;
			operations++;
		}
	}
}

void solve() {
	operations = 0;
	memset(dp, 0, sizeof dp);
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)
		adj[i].clear();
	for (int i = 0; i < n-1; i++) {
		int p;
		cin >> p;
		adj[p-1].push_back(i+1);
	}
	for (int i = 0; i < n; i++)
		cin >> cap[i].first >> cap[i].second;
	
	dfs(0);

	cout << operations << "\n";
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

