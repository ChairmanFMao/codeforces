#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Could just dfs from an arbitrary root that we iterate over

const int mxN = 2e5;
ll n, m, k;
ll values[mxN];
vector<vector<ll> > adj(mxN+1);
set<ll> seen;

void solve() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		adj[i].clear();
	for (int i = 0; i < n; i++)
		cin >> values[i];
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	
	dfs(i);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

