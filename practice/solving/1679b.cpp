#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

const int mxN = 2e5;
pair<ll,ll> change[mxN];
ll base, n, q, total, last;

void solve() {
	base = 0; last = -2; total = 0;
	cin >> n >> q;
	for (ll i = 0; i < n; i++) {
		cin >> change[i].first;
		change[i].second = -1;
		total += change[i].first;
	}
	
	for (ll i = 0; i < q; i++) {
		ll t;
		cin >> t;
		if (t == 1) {
			ll j, x;
			cin >> j >> x;
			j--;
			total += x-(change[j].second > last ? change[j].first : base);
			// I had a silly mistake were I was setting it to x-base
			change[j] = {x,i};
		} else {
			ll x;
			cin >> x;
			base = x;
			total = n*x;
			last = i;
		}
		cout << total << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}
