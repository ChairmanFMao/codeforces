#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Can find the area over which a number will be max

struct Segtree {
	vector<int> tmi, tma;
	int n;
	Segtree(vector<int> v) {
		n = sz(v);
		tmi.resize(n+n);
		tma.resize(n+n);
		for (int i = 0; i < n; i++) {
			tmi[n+i] = v[i];
			tma[n+i] = v[i];
		}
		for (int i = n-1; i > 0; i--) {
			tmi[i] = min(tmi[i+i],tmi[i+i+1]);
			tma[i] = max(tma[i+i],tma[i+i+1]);
		}
	}
 
	int query(int l, int r) {
		int big = 0, small = INT_MAX;
		for (l += n, r += n; l <= r; l>>=1, r>>=1) {
			if (l&1) {
				big = max(big, tma[l]);
				small = min(small, tmi[l]);
				l++;
			}
			if (!(r&1)) {
				big = max(big, tma[r]);
				small = min(small, tmi[r]);
				r--;
			}
		}
		return big%small;
	}
};

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	Segtree tree(a);

	ll out = 0;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			out += !tree.query(i,j);

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

