#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// I think its a graph question
// If a person accuses two others of different roles then
// the roles are linked
// A little like bipartite graphs
// Just set root arbitrarily and then go from there
// loops should be all crewmates or all imposters
// Ended up looking at tutorial
// Just need to generate graph and it can be disjoint
// We then need to check if it is bipartite, if so we take
// the bigger group and make them imposters, otherwise if its
// not bipartite then the graph is not possible
const int mxN = 2e5;
vector<vector<int> > adj(4*mxN);
vector<int> colour(4*mxN), c(2);
int good = 1, n, m;

void dfs(int node) {
	c[colour[node]] += (node < n);
	for (int u : adj[node]) {
		if (colour[u] == -1) {
			colour[u] = colour[node] ^ 1;
			dfs(u);
		} else if (colour[u] != (colour[node] ^ 1))
			good = 0;
	}
}

void solve() {
	good = 1;
	cin >> n >> m;
	for (int i = 0; i < n+m+5; i++) {
		adj[i].clear();
		colour[i] = -1;
	}
	int fake = n+1;
	for (int i = 0; i < m; i++) {
		int a,b; string s; cin >> a >> b >> s; a--; b--;
		// The nodes are on the same team
		if (s[0] == 'c') {
			adj[a].push_back(fake);
			adj[fake].push_back(a);
			adj[b].push_back(fake);
			adj[fake].push_back(b);
			fake++;
		}
		// The nodes are on different teams
		else {
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
	}

	int out = 0;
	for (int i = 0; i < n; i++) {
		if (colour[i] == -1) {
			colour[i] = 0;
			c[0] = c[1] = 0;
			dfs(i);
			out += max(c[0],c[1]);
		}
	}

	cout << (!good ? -1 : out) << "\n";
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

