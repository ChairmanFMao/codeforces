#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Distribute the prime factors well

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	ll out = 1;
	for (ll i : a)
		out *= i;

	cout << (out+n-1)*2022 << "\n";
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

