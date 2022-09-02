#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Looked at editorial
// I think for part 1 we can just brute force
// Only counting the bad triples
// O(n sqrt n) isn't fast enough I think

void solve() {
	ll l, r;
	cin >> l >> r;
	ll out = ((r-l) * (r-l+1) * (r-l-1)) / 6;
	for (ll i = l; i <= r; i++) {
		for (ll k = 1; k*k < i+i; k++) {
			if (!((i+i) % k) && k + (i+i)/k > i && l <= k && (i+i)/k <= r)
				out--;
			if (k*k < i && !(i%k) && k + i/k > i && l <= k && i/k <= r)
				out--;
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

