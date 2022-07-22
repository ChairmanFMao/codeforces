#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// How many nodes he can go from one to another
// Just need to find the number of towns that are only accessible
// from flowers to bees
// Its a tree
// Somehow getting MLE
const int mxN = 3e5;
vector<vector<int> > adj(mxN);
vector<int> valid(mxN,0);
set<int> seen;
int bad = 0, inc = 0;

void dfs(int node) {
	valid[node] += inc;
	for (int u : adj[node])
		if (u != bad && !seen.count(u)) {
			seen.insert(u);
			dfs(u);
		}
}

void solve() {
	int n, x, y;
	cin >> n >> x >> y; x--; y--;
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	inc = 1;
	bad = y;
	seen.insert(x);
	dfs(x);

	inc = 2;
	bad = x;
	seen.clear();
	seen.insert(y);
	dfs(y);

	ll out = 0, one = 0, two = 0, three = 0;
	for (ll i : valid) {
		if (i == 1)
			one++;
		if (i == 2)
			two++;
		if (i == 3)
			three++;
	}

	out += one * (one+three-1);
	out += three * (n-1);
	out += two * (n-1);

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

