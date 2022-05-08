#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// There is a tree and we are trying to find the number of ways to get
// x max security vaults in the grid

const int mxN = 1e5, mxX = 10, MOD = 1e9+7;
// First dimension stores nodes visited
// Second dimension stores the number of high security vaults
// The value is how many times that can occur
ll dp[mxN+1][mxX+1];
vector<vector<int> > adj(mxN);

void solve() {
	memset(dp, 0, sizeof dp);
	int n, m;
	cin >> n >> m;
	
	// This sets up the adjacency list
	for (int i = 0,a,b; i < n-1; i++) {
		cin >> a >> b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	int k, x;
	cin >> k >> x;

	// The first number is the current, the second is the previous
	queue<pair<int,int> > q;
	// This sets the inital values for all of the nodes
	dp[0][0] = 1;
	dp[0][1] = 1;
	// We use 0 as the starting node
	for (int i : adj[0])
		q.push({i,0});

	while(!q.empty()) {
		pair<int,int> current = q.front();
		q.pop();

		// This loops over the number of high security vaults
		for (int i = 0; i <= x; i++) {
			// This is if a low security vault is added
			dp[current.first][i] += dp[current.second][i] * (m-1);
			dp[current.first][i] %= MOD;
			// This is if a high security vault is added
			if (i < x) {
				dp[current.first][i+1] += dp[current.second][i];
				dp[current.first][i+1] %= MOD;
			}
		}
		
		for (int i : adj[current.first])
			if (i != current.second)
				q.push({i,current.first});
	}

	ll out = 0;
	for (int i = 0; i < n; i++)
		out = (out + dp[i][x]) % MOD;

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

