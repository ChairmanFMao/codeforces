#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Actually running the algorithm would be O(n (n + m)) I think
// Not really feasible
// This is kinda a dsu question, I need to practice them
// First we need to find actual minimum spanning tree
// Then we need to find which runs of the algorithm give the same answer
// This currently gets tle due to the O(m n) logic
// Still gets tle even with some optimisations

const int mxN = 1e5;
// Storing the connection and the id of the edge
vector<vector<pair<int,int> > > adj(mxN);
int link[mxN], sizeDSU[mxN], n, m;
vector<char> mst, out;
set<int> seen;

// Does the dfs as the algorithm states
bool dfs(int node) {
	seen.insert(node);
	bool out = 1;
	for (pair<int,int> u : adj[node]) {
		if (!seen.count(u.f)) {
			if (mst[u.s] == '0')
				return 0;
			out &= dfs(u.f);
		}
	}
	return out;
}

// Finds the representative of x's current set
int find(int x) {
	while (x != link[x])
		x = link[x];
	return x;
}

// Unites two sets
void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (sizeDSU[a] < sizeDSU[b])
		swap(a,b);
	sizeDSU[a] += sizeDSU[b];
	link[b] = a;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		link[i] = i;
		sizeDSU[i] = 1;
	}

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adj[a].push_back({b,i});
		adj[b].push_back({a,i});

		// Does Kruskal's algorithm for minimum spanning tree
		if (find(a) != find(b)) {
			mst.push_back('1');
			unite(a,b);
		} else
			mst.push_back('0');
	}

	// out should now contain the minimum spanning tree of the graph
	// I don't think that it is a good idea to just run the algorithm
	// I think it would lead to O(n^2) time
	// I think I will try it anyway
	
	for (int i = 0; i < n; i++) {
		out.push_back(dfs(i) ? '1' : '0');
		seen.clear();
	}

	for (int i = 0; i < n; i++)
		cout << out[i];
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

