#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Minimum number socks with colour change
// I think its just a graph question
// Just find the most common colour in each component
// then add sz - common to the total
const int mxN = 2e5;
vector<int> seen(mxN,0), c(mxN,0);
vector<vector<int> > adj(mxN);
map<int,int> occurs;
int n, m, k, current = 0;

void dfs(int node) {
	seen[node] = 1;
	occurs[c[node]]++;
	current++;
	for (int u : adj[node])
		if (!seen[u])
			dfs(u);
}

void solve() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> c[i];
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int out = 0, best = 0;
	for (int i = 0; i < n; i++) {
		if (seen[i])
			continue;
			
		current = best = 0;
		dfs(i);

		for (auto j = occurs.begin(); j != occurs.end(); j++)
			best = max(best,j->s);
		out += current-best;
		occurs.clear();
	}

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

