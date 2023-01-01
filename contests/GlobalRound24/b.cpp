#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// all of the differences between elements will be added
// need to compute these efficiently
// just go from the largest one downwards?
// we know that all of the elements are unique, this should help
// maybe something to do with prime factors?
// need to avoid O(n^2)
// every number under that has the same mod
// but double counting would need to be removed
// need the smallest dist between numbers
// wa on pretest 2
// gcd of all of the differences
// got this to pass second try

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	ll smallest = a[0];
	for (ll i = 0; i < n; i++)
		smallest = __gcd(smallest,a[i]);

	set<ll> seen;
 	ll out = 0;
	for (ll i = n-1; ~i; i--) {
		if (!seen.count(a[i]%smallest)) {
			out += (a[i]+smallest-1)/smallest;
			seen.insert(a[i]%smallest);
		}
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

