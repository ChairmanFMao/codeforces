#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Cells are blocked from the bottom upwards
// If it attempts to move into a blocked cell or outside it can't do it
// Now wa on test 7
// I guess I'm making progress
// Unsure where the problem is, I think that the code shoudl wor

struct Segtree {
	vector<ll> tr;
	ll n;
	Segtree(vector<ll> v) {
		n = sz(v);
		tr.resize(n+n);
		for (ll i = 0; i < n; i++)
			tr[n+i] = v[i];
		for (ll i = n-1; i > 0; i--)
			tr[i] = max(tr[i+i],tr[i+i+1]);
	}
 
	ll query(ll l, ll r) {
		ll out = -1;
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
	ll n, m;
	cin >> n >> m;
	vector<ll> a(m);
	for (ll& i : a) {
		cin >> i; i--;
	}
	Segtree segtree(a);

	ll q;
	cin >> q;
	for (ll i = 0; i < q; i++) {
		ll xs, ys, xf, yf, k;
		cin >> xs >> ys >> xf >> yf >> k;
		xs--; ys--; xf--; yf--;

		if (abs(xs - xf)%k || abs(ys - yf)%k) {
			cout << "NO\n";
			continue;
		}
		// Moves upwards as high as possible
		ll maxX = (n-1-xs)/k * k + xs;
		// Checks for the highest pillar in the middle
		if (segtree.query(min(ys,yf),max(ys,yf)) >= maxX) {
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

