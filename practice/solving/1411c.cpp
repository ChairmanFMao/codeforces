#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Just need to add another one for every cycle found
// I got the idea and ended up looking at tutorial, struggling a bit with
// the implementation
const int mxN = 1e5;
vector<vector<int> > adj(mxN);
vector<bool> seen(mxN);
int out;

void dfs(int node, int original) {
	seen[node] = 1;
	int count = 0;
	for (int u : adj[node])
		if (!seen[u]) {
			// This will only work on the original call
			if (node == original)
				count++;
			dfs(u, original);
		}

	// Determines if there is a cycle or not
	// This will only trigger if only one endpoint is not done yet
	// If count == 2, the loop should be dealt with elsewhere I think
	if (node == original && count < 2)
		out++;
}

void solve() {
	int n, m;
	cin >> n >> m;
	out = m;
	for (int i = 0; i < n; i++) {
		adj[i].clear();
		seen[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y; x--; y--;
		if (x == y) {
			out--;
			continue;
		}
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	for (int i = 0; i < n; i++)
		if (!seen[i] && sz(adj[i])>1)
			dfs(i,i);

	cout << out << "\n";
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

