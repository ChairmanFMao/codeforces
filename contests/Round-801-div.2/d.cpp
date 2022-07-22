#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Looking at the contraints there should be an O(n^2) way I think
// Algorithm doesn't take into account triangulation which would help
const int mxN = 2e3;
vector<vector<int> > adj(mxN);
int counter = 0, n;
int dist[mxN];

void dfs(int node, int parent, int depth) {
	dist[depth]++;
	for (int i : adj[node])
		if (i != parent)
			dfs(i,node,depth+1);
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		adj[i].clear();
	for (int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	int out = INT_MAX;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			dist[j] = 0;

		dfs(i,-1,0);

		int best = 0;
		for (int j = 0; j < n; j++)
			best = max(best,dist[j]);
		out = min(out,best);
	}

	if (n == 1)
		out = 0;
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

