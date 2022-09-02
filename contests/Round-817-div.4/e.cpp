#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// rects of same dimensions can't fit inside each other
// rectangles cannot be rotated
// just needs to fit inside two different rects
// Can't have an O(n q) solution due to timeout
// map of a kind?
// I can think of an O(q 1000 1000) solution
// I'm trying to think of an offline solution
// 6 seconds time limit as well
// brute force of O(n q) does timeout
// segtree of a kind?
//
// for each height have a segment tree of width
// then just iterate over the heights from smallest to largest
// O(q * 1000 * log 1000)

struct Segtree {
	vector<int> tr;
	int n;
	Segtree(vector<int> v) {
		n = sz(v);
		tr.resize(n+n);
		for (int i = 0; i < n; i++)
			tr[n+i] = v[i];
		for (int i = n-1; i > 0; i--)
			tr[i] = tr[i+i] + tr[i+i+1];
	}
 
	ll query(int l, int r) {
		ll out = 0;
		for (l += n, r += n; l <= r; l>>=1, r>>=1) {
			if (l&1)
				out += tr[l++];
			if (!(r&1))
				out += tr[r--];
		}
		return out;
	}
 
	void update(int pos, int val) {
		tr[n+pos] = val;
		for (int i = (n+pos)>>1; i > 0; i>>=1)
			tr[i] = tr[i+i] + tr[i+i+1];
	}
};

void solve() {
	int n, q;
	cin >> n >> q;
	vector<vector<int>> heights(1001,vector<int>(1001,0));
	for (int i = 0; i < n; i++) {
		int h, w; cin >> h >> w;
		heights[h][w] += w;
	}

	vector<Segtree> segs;
	for (int i = 0; i < 1001; i++)
		segs.push_back(Segtree(heights[i]));

	for (ll i = 0; i < q; i++) {
		ll hs, ws, hb, wb; cin >> hs >> ws >> hb >> wb;
		// hs < hi < hb and ws < wi < wb
		ll out = 0;
		for (ll j = hs+1; j < hb; j++)
			out += j * segs[j].query(ws+1,wb-1);

		cout << out << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

