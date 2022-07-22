#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// I think you might need to store the number of leaves as well
// Somehow you can dp this
// Greedy doesn't work
// We want path to shortest node, we can compress long ones to one node

const int mxN = 3e5;
int cost[mxN];
vector<vector<int> > adj(mxN);

void dfs(int node, int parent) {
	for (int i : adj[node])
		if (i != parent)
			dfs(i, node);

	if (sz(adj[node]) == 1 && node)
		cost[node] = 1;

	if ((sz(adj[node]) == 2 && node) || (sz(adj[node]) == 1 && !node))
		cost[node] = 2;

	if (sz(adj[node]) == 3 || (sz(adj[node]) == 2 && !node)) {
		int current = INT_MAX;
		for (int i : adj[node])
			if (i != parent)
				current = min(current, cost[i]);
		cost[node] = current + 2;
	}
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cost[i] = 0;
		adj[i].clear();
	}

	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	
	dfs(0, 0);

	cout << n-cost[0] << "\n";
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

