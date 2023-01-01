#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// The rating can also decrease
// we need to account for changes

void solve() {
	ll n, x, y;
	cin >> n >> x >> y;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	sort(all(a));
	ll start = x;
	for (ll i = 0; i < n; i++) {
		if (a[i] <= x)
			x++;
		else
			x--;

		if (x >= y) {
			cout << i+1 << "\n";
			return;
		}
	}

	if (x <= start) {
		cout << "-1\n";
		return;
	}

	ll moves = n;
	ll dif = x-start;
	moves += n*((y-x)/dif);
	x += dif*((y-x)/dif);

	for (ll i = 0; i < n; i++) {
		moves++;
		if (a[i] <= x)
			x++;
		else
			x--;

		if (x >= y) {
			cout << moves << "\n";
			return;
		}
	}
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

