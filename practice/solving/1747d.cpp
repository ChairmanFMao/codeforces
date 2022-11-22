#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Getting wa on 549, expecting 1 rather than 2
// now getting wa on a different case, expected 1 got -1
// now getting wa on test 4, expected -1 got 2
// Looked at editorial and it is exactly what I was doing
// Got accepted!
// Just had to binary search the ending value of the xor from the start

void solve() {
	ll n, q;
	cin >> n >> q;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	vector<ll> sp(n+1,0), xp(n+1,0);
	vector<vector<ll> > bp(n+1,vector<ll>(32,0));
	vector<map<ll,set<ll>> > m(2);
	for (ll i = 1; i <= n; i++) {
		sp[i] = sp[i-1] + a[i-1];
		xp[i] = xp[i-1] ^ a[i-1];
		// Stores stuff in the map for later
		m[i&1][xp[i]].insert(i-1);
		for (ll j = 0; j < 30; j++)
			bp[i][j] = bp[i-1][j] + (a[i-1]&(1<<j)?1:0);
	}

	for (ll query = 0; query < q; query++) {
		ll l, r; cin >> l >> r; l--; r--;

		// Gets the bits active in the region
		vector<ll> bits(30,0);
		for (ll i = 0; i < 30; i++)
			bits[i] = bp[r+1][i]-bp[l][i];

		// Checks to make sure that they appear even times
		ll flag = 0, tb = 0;
		for (ll i = 0; i < 30; i++) {
			if (bits[i]&1) {
				cout << "-1\n";
				flag = 1;
				break;
			}
			tb += bits[i];
		}
		if (flag)
			continue;

		// If all zero then we can exit early
		if (!tb) {
			cout << "0\n";
			continue;
		}

		// If the range length is odd we can just do it in one
		if ((r-l)%2 == 0) {
			cout << "1\n";
			continue;
		}

		bool right = query==21&&a[0]==4661764;

		// Now time for the binary search logic stuff
		ll val = xp[r+1], out = 3;
		//cout << "val: " << val << "\n";
		if (a[l] == 0 || a[r] == 0)
			out = min(out,1ll);
		for (int i = 0; i < 2; i++) {
			if (!sz(m[i][val]))
				continue;

			auto ptr2 = m[i][val].upper_bound(l);
			if (ptr2 == m[i][val].end())
				continue;
			ll pos = *ptr2;
			//cout << "i: " << i << " pos: " << *ptr2 << " r: " << r << " l: " << l << "\n";
			if (l < pos && pos < r && (pos-l)%2==0) {
				if (sp[pos+1]-sp[l] == 0 || sp[r+1]-sp[pos+1] == 0)
					out = min(out,1ll);
				else
					out = min(out,2ll);
			}
		}

		right = 0;
		if (right) {
			cout << l << "_" << r << ":_";
			//for (int i = l; i <= r; i++)
				//cout << a[i] << "_";
		}
		cout << (out == 3 ? -1 : out) << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

