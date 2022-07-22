#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Can swap the numbers in each column
// Need to find numbers of cycles, then 2**number

const int MOD = 1e9+7, mxN= 4e5;
vector<vector<int> > adj(mxN);
vector<int> seen(mxN);

void dfs(int node) {
	if (seen[node])
		return;
	seen[node] = 1;
	for (int u : adj[node])
		dfs(u);
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		adj[i].clear();
		seen[i] = 0;
	}
	vector<int> a(n);
	for (int& i : a) {
		cin >> i; i--;
	}
	for (int i = 0; i < n; i++) {
		int b; cin >> b; b--;
		adj[a[i]].push_back(b);
		adj[b].push_back(a[i]);
	}
	
	int cycles = 0;
	for (int i = 0; i < n; i++)
		if (!seen[i]) {
			cycles++;
			dfs(i);
		}

	ll out = 1;
	while (cycles--)
		out = (out * 2) % MOD;

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

