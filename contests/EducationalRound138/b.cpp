#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Greedily take from the sides?
// wa on test 3 somehow
// just kill with smallest bounties to add greedily?
// I think that its always optimal to take from the sides
// would it ever be optimal to remove from the middle?
// sorting for smallest gain possible?

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n), b(n);
	for (ll& i : a)
		cin >> i;
	for (ll& i : b)
		cin >> i;

	ll out = 0, lptr = 0, rptr = n-1;
	while (lptr <= rptr) {
		if (b[lptr] < b[rptr]) {
			out += a[lptr];
			if (lptr < n-1)
				a[lptr+1] += b[lptr];
			lptr++;
		} else {
			out += a[rptr];
			if (rptr > 0)
				a[rptr-1] += b[rptr];
			rptr--;
		}
	}

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

