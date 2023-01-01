#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// This was a test, I wanted to see if I could prove a point
// went back to the python one

const ll mxN = 2e5;
ll prefix[mxN+1], a[mxN];

void solve() {
	ll n, c, d;
	cin >> n >> c >> d;
	for (ll i = 0; i < n; i++)
		cin >> a[i];

	sort(a,a+n);
	reverse(a,a+n);

	for (ll i = 1; i <= mxN; i++)
		prefix[i] = prefix[i-1] + a[i-1];

	for (ll i = 0; i < n; i++)
		a[i] = 0;

	if (prefix[d] >= c) {
		cout << "Infinity\n";
		return;
	}
	if (prefix[1] * d < c) {
		cout << "Impossible\n";
		return;
	}

	ll lower = 0, upper = mxN+1, mid = 0, pl = -1, pu = 0;
	while (lower <= upper) {
		if (lower == pl && upper == pu)
			break;

		mid = (lower+upper)>>1;
		pl = lower; pu = upper;
		ll val = prefix[mid] * (d/mid) + prefix[d%mid];
		if (val >= c)
			lower = mid;
		else
			upper = mid;
	}

	cout << lower-1 << "\n";
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

