#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Want the maximum distribution index possible
// put the highest numbers at the bits that are crossed the most
// need to get all of these sums in a faster way
// we are labelling the edges
// every edge is used n-1 times?
// distance from leaf + n-1 times
// unsure how to check how many times edges used
// product of number of nodes on each side
// not exactly as I am getting lower values for last one
// need to know number of nodes behind each, without O(n^2)
// number of nodes on each side of the current node
// WA on test 2 ;-;

const ll MOD = 1e9+7, mxN = 1e5;
vector<ll> mag(mxN,0);
vector<vector<pair<ll,ll>>> adj(mxN);
int n;

void dfs(ll node, ll p) {
	for (pair<ll,ll> u : adj[node]) {
		if (u.f == p)
			continue;
		dfs(u.f,node);
		mag[node] += mag[u.f];
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		adj[i].clear();
		mag[i] = 1;
	}
	vector<pair<ll,ll> > edges;
	for (int i = 0; i < n-1; i++) {
		ll u, v; cin >> u >> v; u--; v--;
		adj[u].push_back({v,i});
		adj[v].push_back({u,i});
		edges.push_back({u,v});
	}
	ll m;
	cin >> m;
	vector<ll> factors(m);
	for (ll& i : factors)
		cin >> i;
	while (sz(factors) < n-1)
		factors.push_back(1);
	sort(all(factors));
	while (sz(factors) > n-1) {
		factors[sz(factors)-2] = (factors[sz(factors)-2] * factors.back()) % MOD;
		factors.pop_back();
	}

	dfs(0,-1);

	vector<ll> next(n-1,n-1);
	for (int i = 0; i < n-1; i++) {
		ll val = min(mag[edges[i].f],mag[edges[i].s]);
		if ((n-val) * val > next[i])
			next[i] = (n-val) * val;
	}

	sort(all(next));

	ll out = 0;
	for (ll i = 0; i < sz(factors); i++) {
		out = (out + factors[i] * next[i]) % MOD;
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

