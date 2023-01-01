#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Wa on pretest 2
// unsure why this would occur

bool comp(pair<ll,ll> f, pair<ll,ll> s) {
	return f.f < s.f;
}

void solve() {
	ll n, k;
	cin >> n >> k;
	vector<pair<ll,ll> > a(n);
	multiset<ll> power;
	for (ll i = 0; i < n; i++)
		cin >> a[i].f;
	for (ll i = 0; i < n; i++) {
		cin >> a[i].s;
		power.insert(a[i].s);
	}

	// sort them by health
	sort(all(a),comp);

	ll dmg = 0, ptr = 0;
	while (k > 0 && ptr < n) {
		dmg += k;
		while (ptr < n && dmg >= a[ptr].f) {
			power.erase(power.find(a[ptr].s));
			ptr++;
		}
		if (sz(power))
			k -= *power.begin();
	}

	cout << (ptr == n ? "YES" : "NO") << "\n";
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

