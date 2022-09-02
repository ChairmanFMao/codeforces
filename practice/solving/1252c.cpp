#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// grid formed by r + c for those coordinates
// Need to look for streaks of evens or odds
// Starts as either: even + even or odd + odd
// Will not be able to move off this formation
// Need an all even or an all odd pathway
// Can't brute force due to 1e12 size of grid
// Segment tree to query inbetween if there is even or odd
// The implementation I have is very messy however, it works!
// I also did this one without the editorial which was cool

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
	int n, q;
	cin >> n >> q;
	vector<int> r(n), c(n);
	for (int& i : r)
		cin >> i;
	for (int& i : c)
		cin >> i;

	vector<int> ro(n), co(n), re(n), ce(n);
	for (int i = 0; i < n; i++) {
		ro[i] = r[i] & 1;
		co[i] = c[i] & 1;
		re[i] = !ro[i];
		ce[i] = !co[i];
	}
	
	Segtree ros(ro), cos(co), res(re), ces(ce);

	for (int i = 0; i < q; i++) {
		int ra, ca, rb, cb; cin >> ra >> ca >> rb >> cb;
		ra--; ca--; rb--; cb--;

		int valid = 1;

		if (r[ra] & 1) {
			valid &= !res.query(min(ra,rb),max(ra,rb));
			valid &= !ces.query(min(ca,cb),max(ca,cb));
		} else {
			valid &= !ros.query(min(ra,rb),max(ra,rb));
			valid &= !cos.query(min(ca,cb),max(ca,cb));
		}

		cout << (valid ? "YES" : "NO") << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

