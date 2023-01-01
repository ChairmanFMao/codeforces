#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// It needs to be strictly increasing ;-;

void solve() {
	ll n, k;
	cin >> k >> n;

	ll out = 100;
	for (ll i = 1; i <= k; i++) {
		vector<ll> current = {1};
		for (ll j = 2; j <= i; j++)
			current.push_back(j);
		ll val = i, dif = 2;
		while (sz(current) < k) {
			val += dif;
			current.push_back(val);
			dif++;
		}
		if (*max_element(all(current)) <= n) {
			out = min(out,i);
		}
	}

	vector<ll> current = {1};
	for (ll j = 2; j <= out; j++)
		current.push_back(j);
	ll val = out, dif = 2;
	while (sz(current) < k) {
		val += dif;
		current.push_back(val);
		dif++;
	}

	for (ll i : current)
		cout << i << " ";
	cout << "\n";
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

