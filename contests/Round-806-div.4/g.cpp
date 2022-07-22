#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Must be done from 1 to n
// I was sorting it ;-;
// I have a feeling that this is dp
// I think that the dp leads to O(n^2) however
// I think that its optimal to never use bad keys until you just use all

void solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	vector<ll> dp(n,0);
	for (ll i = 0; i < n; i++)
		for (ll j = i; j < n && j < i+32; j++)
			dp[i] += a[j] >> (j-i+1);

	vector<ll> totals(n+1,0);
	for (ll i = 0; i < n; i++) {
		totals[i+1] = totals[i] - k + a[i];
		totals[i] += dp[i];
	}

	ll out = 0;
	for (ll i : totals)
		out = max(i,out);

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

