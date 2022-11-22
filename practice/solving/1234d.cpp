#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// this is a segment tree type thing
// just with maps?
// tle on test 3?
// gets past the time limit just
// Using a bitmask with an integer is much faster than using a
// map for each of the characters

struct Segtree {
	vector<int> tr;
	int n;
	vector<char> current;
	Segtree(vector<char> v) {
		n = sz(v);
		tr.resize(n+n);
		for (int i = 0; i < n; i++) {
			tr[n+i] |= 1<<(v[i]-97);
			current.push_back(v[i]-97);
		}
		for (int i = n-1; i > 0; i--)
			tr[i] = tr[i+i] | tr[i+i+1];
	}
 
	int query(int l, int r) {
		int out = 0;
		for (l += n, r += n; l <= r; l>>=1, r>>=1) {
			if (l&1)
				out |= tr[l++];
			if (!(r&1))
				out |= tr[r--];
		}
		return __builtin_popcount(out);
	}
 
	void update(int pos, int val) {
		tr[n+pos] &= !(1<<current[pos]);
		tr[n+pos] |= 1<<(val-97);
		for (int i = (n+pos)>>1; i > 0; i>>=1)
			tr[i] = tr[i+i] | tr[i+i+1];
		current[pos] = val-97;
	}
};

void solve() {
	string s;
	int q;
	cin >> s >> q;
	vector<char> vec;
	for (char c : s)
		vec.push_back(c);

	Segtree seg(vec);
	
	for (int i = 0; i < q; i++) {
		int a;
		cin >> a;
		if (a == 1) {
			int pos;
			char c;
			cin >> pos >> c;
			pos--;
			seg.update(pos,c);
		} else {
			int l, r; cin >> l >> r; l--; r--;
			cout << seg.query(l,r) << "\n";
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

