#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// wa on pretest 3 somehow
// I did something silly and this fst in contest

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	ll small = *min_element(all(a)), big = *max_element(all(a));
	ll dif = big - small;
	ll out = 0;
	map<ll,ll> m;
	for (ll i : a)
		m[i]++;

	set<ll> s(all(a));
	vector<ll> u(all(s));
	for (ll i : s) {
		ll val = m[i];
		m[i]--;
		out += val * m[i+dif] * (dif == 0 ? 1 : 2);
		m[i]++;
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

