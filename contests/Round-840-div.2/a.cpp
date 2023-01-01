#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	ll big = 0, small = INT_MAX;
	for (ll i : a) {
		big |= i;
		small &= i;
	}

	cout << big-small << "\n";
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

