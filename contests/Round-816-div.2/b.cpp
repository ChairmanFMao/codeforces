#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Beauty of b, sum of s, divided by k
// zero is allowed

void solve() {
	ll n, k, b, s;
	cin >> n >> k >> b >> s;
	
	ll extra = (k-1) * n;
	if (extra + b*k < s || k*b > s) {
		cout << "-1\n";
		return;
	}

	if (s > k*b)
		extra = s - k*b;
	else
		extra = 0;

	for (int i = 0; i < n; i++) {
		ll current = 0;
		if (!i)
			current += k*b;
		if (extra) {
			ll add = min(extra,k-1);
			current += add;
			extra -= add;
		}
		cout << current << " ";
	}
	cout << "\n";
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

