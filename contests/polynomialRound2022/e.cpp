#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Maybe this is dynamic programming?
// actually due to the constraints I'm not sure
// I don't think that its dynamic programming
// Maybe just move the other person as close as they need to be
// Unsure how to make steps taken minimal
// when piece 1 moves out, make piece 2 also do all the ones that
// they can in that part of the tree
// find distances from any nodes in O(log n) via lca precalc
// and a binary search
// perhaps something recursive here
// where once you go into a new tree you just do the same thing
// again but just with it not being possible to leave
// if 1 and 2 have pieces in the subtree move them both that way

void solve() {
	ll n, d;
	cin >> n >> d;
	vector<vector<ll> > adj(n);
	for (ll i = 0; i < n-1; i++) {
		ll u, v; cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	ll aLen, bLen;
	cin >> aLen;
	vector<ll> a(aLen);
	for (ll& i : a) {
		cin >> i; i--;
	}
	cin >> bLen;
	vector<ll> b(bLen);
	for (ll& i : b) {
		cin >> i; i--;
	}

	vector<ll> val(n,0);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

