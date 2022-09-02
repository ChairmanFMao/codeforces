#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// insert all of 1 to x for smallest abs
// min at one end, max at other

void solve() {
	ll n, x;
	cin >> n >> x;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	ll mi = *min_element(all(a)), ma = *max_element(all(a));
	ll out = 0;
	for (int i = 0; i < n-1; i++)
		out += abs(a[i] - a[i+1]);

	ll f = min(a[0],a[n-1]), b = max(a[0],a[n-1]);
	if (1 < mi)
		out += min(f-1,abs(mi-1)*2);
	if (x > ma)
		out += min(x-b, abs(x-ma)*2);

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

