#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// just turn array into increasing order
// for all ai are turned into zero
// I can think of a greedy sort of thing unsure tho
// just need to check if there is a smaller number after
// if so we need to do a removal - segment tree?
// Just do the operation twice for false ones

struct Segtree {
	vector<int> tr;
	int n;
	Segtree(vector<int> v) {
		n = sz(v);
		tr.resize(n+n);
		for (int i = 0; i < n; i++)
			tr[n+i] = v[i];
		for (int i = n-1; i > 0; i--)
			tr[i] = min(tr[i+i],tr[i+i+1]);
	}
 
	int query(int l, int r) {
		int out = INT_MAX;
		for (l += n, r += n; l <= r; l>>=1, r>>=1) {
			if (l&1)
				out = min(out, tr[l++]);
			if (!(r&1))
				out = min(out, tr[r--]);
		}
		return out;
	}

	void update(int pos, int val) {
		tr[n+pos] = val;
		for (int i = (n+pos)>>1; i > 0; i>>=1)
			tr[i] = min(tr[i+i],tr[i+i+1]);
	}
};

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	Segtree seg(a);
	map<int, vector<int> > m;
	for (int i = 0; i < n; i++)
		m[a[i]].push_back(i);

	int out = 0;
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < n; i++) {
			if (seg.query(i,n-1) < a[i]) {
				for (int j : m[a[i]]) {
					seg.update(j,0);
					a[j] = 0;
				}
				out++;
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

