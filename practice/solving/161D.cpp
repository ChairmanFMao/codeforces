#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Currently TLE on test 17 - even with improvements unsure what to do now
// I think that the dfs might be too slow but, then idk what to do
// Through extrapolation I think my code would take like 6 seconds not 3
// Had to switch to arrays from maps, they were a lot faster

const int mxN = 5e4;
vector<vector<int> > adj(mxN);
int dist[mxN][501];
int n, k;
ll out = 0;

void dfs(int index, int prev) {
	vector<int> p;

	// All nodes have a distance of zero to themselves
	dist[index][0] = 1;

	// Iterates over all the children to dfs first
	for (int i : adj[index])
		if (i != prev) {
			dfs(i,index);
			p.push_back(i);
		}
	
	// Adds all of the children's values to the current index
	for (int i = 0; i < (int)p.size(); i++)
		for (int j = 0; j < k; j++)
			dist[index][j+1] += dist[p[i]][j];
	
	// Adds connections using the current node as a hub
	for (int j = 0; j < (int)p.size(); j++) {
		for (int i = 0; i < k; i++)
			// (hub node other - adjacent node current) * adjacent node current
			out += (dist[index][k-i-1]-(i == k-1 ? 0 : dist[p[j]][k-i-2])) * dist[p[j]][i];
		out += dist[p[j]][k];
	}
}

void solve() {
	// Sets up the adjacency matrix
	cin >> n >> k;
	for (int i = 0,a,b; i < n-1; i++) {
		cin >> a >> b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}

	// We choose an arbitrary node as our root
	dfs(0,0);

	out += dist[0][k];

	cout << out/2 << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
