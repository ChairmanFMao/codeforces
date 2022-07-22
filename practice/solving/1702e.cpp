#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// This is actually a very interesting problem
// Some ideas used from comments and other's solutions
const int mxN = 2e5;
vector<vector<int> > adj(mxN);
vector<int> colour(mxN);
int bad = 0;

void dfs(int current, int c) {
	colour[current] = c;
	for (int i : adj[current]) {
		if (colour[i] == c)
			bad = 1;
		else if (colour[i] == 0)
			dfs(i, 3-c);
	}
}

void solve() {
	bad = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		adj[i].clear();
		colour[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
		if (a==b)
			adj[a].push_back(-1);
	}

	for (int i = 0; i < n; i++)
		if (sz(adj[i]) != 2) {
			cout << "NO\n";
			return;
		}

	for (int i = 0; i < n; i++)
		if (!colour[i])
			dfs(i, 1);

	cout << (bad ? "NO" : "YES") << "\n";
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

