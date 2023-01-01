#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// This seems like it might be dynamic programming
// This is quite a fun problem
// m is very small
// need to get from start to end and can only do jumps of 1 or 2
// need to always buy the starting and ending colours
// do a dp with storing where you are and what you have activated
// then store the minimum cost to get there
// Actually storing activated might be difficult
// it could easily lead to something exponential
// it doesn't matter when we buy each colour
// always best to greedily go as far as possible on tiles which
// have already been activated
// if there is ever a streak of 2 of one colour in a row then we
// need to buy that colour
// maybe do it like a minimum spanning tree kinda?
// when you add a colour we add both of the ones behind into the
// same dsu and we keep repeating this with the smallest edges
// until the starting node is in the same node
// This could lead to unnecessary edges tho
// just only add the costs necessary on the dsu path maybe?
// actually I'm not sure if the minimum spanning tree approach
// would always give the optimal solution
// I think that I'll have a go doing it as its my best idea so far
// This current approach doesn't work on the last test case
// I think that this is a really interesting problem even though
// I don't think that I will manage to solve it in contest

struct Dsu {
	vector<pair<ll,ll>> link;
	vector<ll> sizeOf;
	Dsu(ll n) {
		link.assign(n,{-1,-1});
		sizeOf.assign(n,1);
	}
	// This finds the represetative for an index
	ll find(ll x) {
		while (-1 != link[x].f)
			x = link[x].f;
		return x;
	}
	// This unites two sets
	void unite(ll a, ll b, ll val, vector<ll>& c) {
		a = find(a);
		b = find(b);
		if (sizeOf[a] < sizeOf[b])
			swap(a,b);
		if (a == b && c[val] < c[link[b].s]) {
			link[b].s = val;
			return;
		}
		if (a == b)
			return;
		sizeOf[a] += sizeOf[b];
		link[b] = {a,val};
	}

	set<ll> path(ll x) {
		set<ll> ret;
		while (-1 != link[x].f) {
			ret.insert(link[x].s);
			x = link[x].f;
		}
		return ret;
	}
};

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<ll> c(n), x(m);
	for (ll& i : c)
		cin >> i;
	for (ll& i : x)
		cin >> i;

	// This creates the dsu
	Dsu moves = Dsu(n+1);
	ll out = 0;

	vector<pair<ll,ll> > c2;
	for (ll i = 0; i < m; i++)
		c2.push_back({x[i],i});

	sort(all(c2));
	ll ptr = 0;
	while (ptr < sz(c2) && moves.find(0) != moves.find(n)) {
		for (ll j = 0; j < n; j++)
			if (c[j] == c2[ptr].s)
				for (ll k = max(0ll,j+1-2); k < j+1; k++)
					moves.unite(moves.find(j+1),moves.find(k),c2[ptr].s, x);
		ptr++;
	}

	set<ll> s2 = moves.path(0);
	vector<ll> u2(all(s2));
	for (ll i : u2)
		out += x[i-1];

	cout << out << "\n";
}

int main(void) {
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	solve();
}

