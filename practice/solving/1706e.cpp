#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// I did look at editorial, you do kruskals for mst
// I think I should make some template stuff like segtree and dsu
// A lot of this is taken from the sample solution
// However I get how the logic works
// I think I need to make some templates at some point
// The Dsu generates the largest weight from i to i+1
// The segment tree gets the max of (i,i+1), (i+1,i+2), ... in good time

struct Dsu {
	vector<int> link, wt, sizeOf;
	Dsu(int n) {
		link.assign(n,-1);
		sizeOf.assign(n,1);
		wt.resize(n,INT_MAX);
	}
	// This finds the represetative for an index
	int find(int x) {
		while (-1 != link[x])
			x = link[x];
		return x;
	}
	// This unites two sets
	void unite(int a, int b, int weight) {
		a = find(a);
		b = find(b);
		if (a == b)
			return;
		if (sizeOf[a] < sizeOf[b])
			swap(a,b);
		sizeOf[a] += sizeOf[b];
		link[b] = a;
		wt[b] = weight;
	}
	// This gets the max weight on a journey between 2 nodes
	int weight(int a, int b) {
		int w = 0;
		while (a != b) {
			if (wt[a] < wt[b])
				w = wt[a], a = link[a];
			else
				w= wt[b], b = link[b];
		}
		return w;
	}
};

struct Segtree {
	vector<int> tr;
	int n;
	Segtree(vector<int> v) {
		n = sz(v);
		tr.resize(n+n);
		for (int i = 0; i < n; i++)
			tr[n+i] = v[i];
		for (int i = n-1; i > 0; i--)
			tr[i] = max(tr[i+i],tr[i+i+1]);
	}

	int query(int l, int r) {
		int out = 0;
		for (l += n, r += n; l <= r; l>>=1, r>>=1) {
			if (l&1)
				out = max(out, tr[l++]);
			if (!(r&1))
				out = max(out, tr[r--]);
		}
		return out;
	}
};

void solve() {
	int n, m, q;
	cin >> n >> m >> q;

	Dsu dsu(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; u--; v--;
		dsu.unite(u,v,i+1);
	}

	vector<int> weights(n-1);
	for (int i = 0; i < n-1; i++)
		weights[i] = dsu.weight(i,i+1);

	Segtree segree(weights);
	while (q--) {
		int l, r; cin >> l >> r; l--; r--;
		cout << (l==r?0:segree.query(l,r-1)) << " ";
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

