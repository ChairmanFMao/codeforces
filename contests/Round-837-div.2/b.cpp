#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Something with a binary search I think
// maybe a dsu and check if people are all distinct
// might also just be possible with 2 ptr

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<vector<ll> > adj(n);
	for (ll i = 0; i < m; i++) {
		ll a, b; cin >> a >> b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	ll out = 0, ptr = 0;
	queue<ll> q;
	set<ll> s;
	while (ptr < n) {
		ll bad = 0;
		for (ll i : adj[ptr])
			if (s.count(i))
				bad = 1;
		
		if (bad) {
			ll tmp = q.front();
			q.pop();
			s.erase(tmp);
			continue;
		}

		q.push(ptr);
		s.insert(ptr);
		ptr++;
		out += sz(q);
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

