#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// I looked at a bit of the tutorial, you need to use dfs and dp
// Not that different to what I was doing, just needed to cache values using dp
// This just makes the program efficient enough to pass all of the tests

const int mxN = 2e5, INF = 1e9;
vector<vector<int> > adj(mxN);
vector<vector<int> > antiAdj(mxN);
// This stores the max length from a node
int dp[mxN];
int n, m;

// This calls a search to check all of the nodes
int solve2(int current) {
	// If the value has already been calculated, we return that value
	if (dp[current] != -1)
		return dp[current];
	// If the node has valid input and output we process it
	if (sz(antiAdj[current]) > 1 && sz(adj[current]) > 1) {
		dp[current] = 1;
		// Here we loop through all of the possible successors
		for (int i : adj[current])
			dp[current] = max(dp[current], solve2(i)+1);
	} 
	// Otherwise, if the inwards is greater than 1 we can set it to 1
	else if (sz(antiAdj[current]) > 1)
		dp[current] = 1;
	// This means that the node is not part of the graph after processing
	else
		dp[current] = -INF;

	return dp[current];
}

void solve() {
	// This just clears the adjacency matrixes
	for (int i = 0; i < mxN; i++) {
		adj[i].clear();
		antiAdj[i].clear();
	}
	cin >> n >> m;
	
	// This takes in all the edges that make up the graph
	for (int i = 0; i < m; i++) {
		int start, end;
		cin >> start >> end;
		start--;
		end--;
		adj[start].push_back(end);
		antiAdj[end].push_back(start);
	}

	// This searches from each node
	memset(dp, -1, sizeof dp);
	int out = 1;
 	for (int i = 0; i < n; i++) {
		if (sz(adj[i]) > 1) {
			for (int j : adj[i])
				out = max(out, solve2(j)+1);
		}
	}

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

