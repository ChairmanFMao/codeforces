#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	ll m, sum;
	cin >> m >> sum;
	vector<ll> a(m);
	for (ll& i : a)
		cin >> i;

	set<ll> s(all(a));

	ll current = 1;
	while (sum > 0) {
		if (!s.count(current)) {
			sum -= current;
			s.insert(current);
		}
		current++;
	}

	if (sum != 0) {
		cout << "NO\n";
		return;
	}

	vector<ll> v(all(s));
	ll big = *max_element(all(v));
	for (ll i = 1; i <= big; i++) {
		if (!s.count(i)) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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

