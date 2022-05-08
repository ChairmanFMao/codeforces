#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Get wa on the big input one
// Its not even integer overflow, the output is too high by 180k
// It was just an off by one error that I managed to get

void solve() {
	ll nl, xl;
	cin >> nl >> xl;
	__int128 x = xl, n = nl;
	vector<ll> a(nl);
	for (__int128 i = 0; i < n; i++)
		cin >> a[i];

	sort(all(a));

	vector<__int128> total(n);
	__int128 tot = 0;
	for (__int128 i = 0; i < n; i++) {
		tot += a[i];
		total[i] = tot;
	}

	__int128 ind = -1;
	for (__int128 i = 0; i < n; i++)
		if (total[i] <= x)
			ind = i;

	// Out stores the total number of packs
	// extra stores the increase in value
	__int128 out = 0, extra = 0, one = 1, zero = 0;
	for (__int128 i = ind; i >= 0; i--) {
		__int128 times = (x - total[i] - (extra*(i+one)))/(i+one) + (x-total[i]-(extra*(i+one)) >= 0 ? one : zero);
		out += times * (i+one);
		extra += times;
	}

	ll outll = (ll)out;
	cout << outll << "\n";
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

