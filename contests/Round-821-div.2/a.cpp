#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// try to arrange them all at the front

void solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	ll out = 0;
	for (int i = 0; i < k; i++) {
		ll current = 0;
		for (int j = i; j < n; j+=k)
			current = max(a[j],current);

		out += current;
	}

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

