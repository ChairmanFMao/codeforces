#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Both play optimally
// Just removing nodes furthest from end?
// O(n^2) would work here due to mxN = 1000
// Just recalculate the whole graph after removals
// TLE on test case 11, I need to optimse but my logic is right
// spread out rather than spread in
const int mxN = 1000;
vector<vector<int> > adj(mxN);
vector<int> dfsSeen(mxN,0), seen(mxN,0), dist(mxN,0);
int n, x;

void dfs(int node, int dis) {
	if (seen[node])
		return;
	dist[node] = dis;
	dfsSeen[node] = 1;
	for (int u : adj[node])
		if (!dfsSeen[u])
			dfs(u,dis+1);
}

bool leaf(int node) {
	int out = 0;
	for (int u : adj[node])
		if (!seen[u])
			out++;
	return out <= 1;
}

void solve() {
	cin >> n >> x; x--;
	for (int i = 0; i < n; i++) {
		adj[i].clear();
		seen[i] = 0;
	}
	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}

	fill(all(dfsSeen),0);
	fill(all(dist),1001);
	dfs(x,0);

	int turn = 0;
	while (!leaf(x)) {
		int best = 0, index = -1;
		for (int i = 0; i < n; i++)
			if (!seen[i] && leaf(i) && dist[i] > best) {
				best = dist[i];
				index = i;
			}
		
		seen[index] = 1;
		fill(all(dist),1001);
		fill(all(dfsSeen),0);
		dfs(x,0);

		turn ^= 1;
	}

	cout << (turn ? "Ashish" : "Ayush") << "\n";
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

