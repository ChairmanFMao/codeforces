#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Need to reduce all of a and b with the first operation
// Then check if they are equal

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;
	ll k;
	cin >> k;
	vector<ll> b(k);
	for (ll& i : b)
		cin >> i;

	vector<pair<ll,ll> > af(n), bf(k);

	for (int i = 0; i < n; i++) {
		ll counter = 1;
		while (!(a[i]%m)) {
			counter *= m;
			a[i] /= m;
		}
		af[i] = {a[i],counter};
	}
	for (int i = 0; i < k; i++) {
		ll counter = 1;
		while (!(b[i]%m)) {
			counter *= m;
			b[i] /= m;
		}
		bf[i] = {b[i],counter};
	}

	ll aptr = 0, bptr = 0;
	while (aptr < n && bptr < k) {
		if (af[aptr].first != bf[bptr].first) {
			cout << "NO\n";
			return;
		}
		ll small = min(af[aptr].second, bf[bptr].second);
		af[aptr].second -= small;
		bf[bptr].second -= small;
		if (!af[aptr].second)
			aptr++;
		if (!bf[bptr].second)
			bptr++;
	}

	cout << (aptr == n && bptr == k ? "YES" : "NO") << "\n";
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

