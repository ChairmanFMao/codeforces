#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Can only select leaf nodes

void solve() {
	int n;
	cin >> n;
	vector<vector<int> > adj(n);
	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		if (sz(adj[i]) == 2) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

