#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// For each one i needs to be the gcd for them all to be unique

void solve() {
	ll n, l, r;
	cin >> n >> l >> r;

	vector<ll> out(n);
	for (ll i = 1; i <= n; i++) {
		ll start = (l/i)*i;
		if (start < l)
			start += i;

		if (start > r) {
			cout << "NO\n";
			return;
		} else {
			out[i-1] = start;
		}
	}

	cout << "YES\n";
	for (ll i : out)
		cout << i << " ";
	cout << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

