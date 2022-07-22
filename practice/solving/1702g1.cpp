#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Need to find a path through all of the vertices that doesn't pass
// through any of the vertices twice
// Need to choose a leaf of the group
// Then dfs through the graph, if all can be found on a dfs to a leaf
// then it works and the set is passable
// Epicly accepted - only used a bit of the tutorial

const int mxN = 2e5;
vector<vector<int> > adj(mxN);
vector<int> depth(mxN), p(mxN);
set<int> pSet;
int best;

void deep(int current, int parent, int currentDepth) {
	depth[current] = currentDepth;
	for (int i : adj[current])
		if (i != parent)
			deep(i, current, currentDepth+1);
}

void dfs(int current, int parent, int score) {
	if (pSet.count(current))
		score++;
	best = max(best, score);
	for (int i : adj[current])
		if (i != parent)
			dfs(i, current, score);
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	deep(0, -1, 0);

	int q;
	cin >> q;
	while (q--) {
		int k;
		cin >> k;
		pSet.clear();
		for (int i = 0; i < k; i++) {
			cin >> p[i]; p[i]--;
			pSet.insert(p[i]);
		}

		int deepest = -1, node = -1;
		for (int i = 0; i < k; i++)
			if (depth[p[i]] > deepest) {
				node = p[i];
				deepest = depth[p[i]];
			}

		best = 0;
		dfs(node, -1, 0);
		cout << (best == k ? "YES" : "NO") << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

