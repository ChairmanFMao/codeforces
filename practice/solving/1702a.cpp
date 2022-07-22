#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	ll n;
	cin >> n;
	ll out = LONG_LONG_MAX;
	for (ll i = 1; i <= 1e10; i *= 10)
		if (n >= i)
			out = min(out, n-i);
	
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

