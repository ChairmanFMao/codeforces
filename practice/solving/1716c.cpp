#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Want to visit the largest element as late as possible
// Just set the largest element to be last?
// More difficult with multiple largest elements
// If we were to try with every one, O(m^2)
// Looked at solution basically in comments of the post
// Also decided to look at tutorial
// Its basically what I was thinking, dp to O(m) solution

void solve() {
	ll m;
	cin >> m;
	vector<vector<ll> > a(2,vector<ll>(m));
	for (vector<ll>& i : a)
		for (ll& j : i)
			cin >> j;

	vector<vector<ll> > dp(2,vector<ll>(m+1,INT_MIN));

	for (ll i = 0; i < 2; i++)
		for (ll j = m-1; ~j; j--)
			dp[i][j] = max(dp[i][j+1]-1,max(dp[i][j],dp[i^1][j] - (2* (m-j) - 1)));

	ll pr = dp[0][0] - 1, out = LONG_LONG_MAX;

	for (ll i = 0; i < m; i++) {
		out = min(out, max(pr, max(dp[i&1][i+1] - 2*i - 1, dp[(i&1)^1][i] - 2*m +1)));

		pr = max(pr, dp[(i&1)^1][i+1] - 2*i - 1);
		out = min(out, max(pr, dp[(i&1)^1][i+1] - 2*i - 2));
		if (i < m-1)
			pr = max(pr, dp[(i&1)^1][i+1] - 2*i - 2);
	}

	cout << out + 2*m << "\n";
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

