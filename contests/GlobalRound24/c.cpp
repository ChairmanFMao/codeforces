#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Something like a dsu maybe?
// the altitudes are all capped under 1e6 which may be useful
// want the maximum number of edges
// can't have an ascending or descending streak of 3
// connect all nodes to the smallest node?
// designate some of nodes to be children kinda
// iterate from the smallest node, we need all parents to be
// greater than its value
// almost like a maximum spanning tree problem
// no self loops or multiple edges
// I don't think that just greedily pairing is a good idea
// something like bipartite maybe?
// yea need to maximize the edges in a bipartite graph
// blue can be maxima and red can be minima

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	map<ll,ll> m;
	for (ll i : a)
		m[i]++;

	ll tot = n, out = 0;
	for (auto i = m.begin(); i != m.end(); i++) {
		tot -= i->s;
		out = max(out,tot * (n-tot));
	}

	if (sz(m) == 1)
		out = max(out,n/2);

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

