#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Can only invite pairs
// WA on pretest 2 ;-;
// approach kinda probabalistic
// graph with an even number of edges filled in
// smallest possible pair that contain each other
// both need to be even

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	map<ll,vector<ll>> mapping;
	for (ll i = 0; i < m; i++) {
		ll x, y; cin >> x >> y; x--; y--;
		mapping[x].push_back(y);
		mapping[y].push_back(x);
	}
	
	// There could potentially have to be O(n^2) ;-;
	ll out = m&1 ? INT_MAX : 0;
	for (int i = 0;(m&1) && i < n; i++) {
		if (sz(mapping[i]) & 1)
			out = min(out, a[i]);
		else {
			for (int j = 0; j < sz(mapping[i]); j++) {
				if (sz(mapping[mapping[i][j]]) % 2 == 0) {
					out = min(out,a[i] + a[mapping[i][j]]);
				}
			}
		}
	}

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

