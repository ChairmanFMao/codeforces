#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n;
	cin >> n;
	vector<int> w(n);
	for (int& i : w)
		cin >> i;
	vector<vector<int> > adj(n);
	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	ll total = 0;
	vector<int> dupe;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < sz(adj[i])-1; j++)
			dupe.push_back(w[i]);
		total += w[i];
	}

	sort(all(dupe),greater<int>());
	cout << total << " ";
	for (int i = 0; i < n-2; i++) {
		total += dupe[i];
		cout << total << " ";
	}
	cout << "\n";
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

