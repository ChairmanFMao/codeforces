#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Just store the max and min on each side
// if left dif <= right dif then we are good
// just try max, min and midpoint
// getting wa on test 2
// checking the mean value doesn't solve it
// maybe it needs to be rounded
// The rounding didn't solve the issue

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	ll tot = accumulate(all(a),0ll);
	ll big = *max_element(all(a)), small = *min_element(all(a));
	vector<ll> vals = {big,small,(ll)round((long double)tot/(long double)n),(big+small)/2,(big+small+1)/2};

	for (ll i : vals) {
		vector<ll> tmp;
		for (ll j : a)
			tmp.push_back(abs(j-i));
		ll good = 1;
		for (ll j = 0; j < n-1 && good; j++)
			if (tmp[j] > tmp[j+1])
				good = 0;

		if (good) {
			cout << i << "\n";
			return;
		}
	}
	cout << "-1\n";
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

