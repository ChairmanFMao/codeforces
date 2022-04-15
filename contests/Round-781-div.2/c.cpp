#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

// Need to find furthest two points on the graph and infect both of them
// You can only spread one child for each node, I thought it was exponential
// ;-; this makes the problem very different to what I was thinking, need to read the
// question properly and carefully
// Ended up using tutorial and using a binary search for the extra operations

void solve() {
	ll n;
	cin >> n;
	vt<ll> adj(n+1);
	// This is for the root node
	adj[0] = 1;
	for (ll i = 0,a; i < n-1; i++) {
		cin >> a;
		adj[a]++;
	}

	sort(adj.rbegin(),adj.rend());
	while (sz(adj) && adj[sz(adj)-1] <= 0)
		adj.pop_back();
	
	ll out = sz(adj);
	for (ll i = 0; i < sz(adj); i++)
		adj[i] -= sz(adj)-i;
	
	sort(adj.rbegin(),adj.rend());
	while (sz(adj) && adj[sz(adj)-1] <= 0)
		adj.pop_back();

	ll low = 0, up = 1e9, mid, current = 0;
	bool flag = 0;
	while (1) {
		if (flag)
			break;
		if (low >= up-1)
			flag = 1;
		mid = (low+up)>>1;
		current = 0;
		for (ll i : adj)
			current += max(0ll,i-mid);
		if (current <= mid)
			up = mid;
		else
			low = mid;
	}

	cout << out + up << "\n";
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

