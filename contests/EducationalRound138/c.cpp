#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Alice deleting the biggest possible below bound
// Bob raising the smallest possible above bound
// some brute force simulation thing I think
// need to get n-k elements above 1 for alice to lose
// to remove elements we can just set to them to inf
// wa on test 2 now
// Bob should do the smallest that gets it above
// otherwise just do any

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;
	sort(all(a));

	ll out = 0;
	// This is the value of k
	for (ll i = 0; i <= 100; i++) {
		vector<ll> b(all(a));
		ll win = 1;
		// These are for all of the turns
		for (ll j = 0; j < i; j++) {
			// This is Alice's turn
			ll biggest = 0, index = -1;
			for (ll k = 0; k < n; k++) {
				if (b[k] == INT_MAX)
					continue;
				if (b[k] > biggest && b[k] <= i-j) {
					biggest = b[k];
					index = k;
				}
			}
			if (index == -1) {
				win = 0;
				break;
			}
			b[index] = INT_MAX;

			// This is Bob's turn
			sort(all(b));
			for (ll k = 0; k < n; k++) {
				if (b[k] == INT_MAX)
					continue;
				b[k] += i-j;
				break;
			}
		}

		if (win)
			out = max(out,i);
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

