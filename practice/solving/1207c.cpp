#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	ll n, a, b;
	string s;
	cin >> n >> a >> b >> s;

	// First dimension is for place, second is for height
	vector<vector<ll> > dp(n+1,vector<ll>(2));
	dp[0][1] = 1e17;
	ll out = n * b + b + n * a;
	for (ll i = 0; i < n; i++) {
		dp[i+1][0] = min(dp[i][0], dp[i][1] + a + b);
		dp[i+1][1] = min(dp[i][1], dp[i][0] + a) + b;
		if (s[i] == '1')
			dp[i+1][0] = 1e17;
	}

	cout << out + dp[n][0] << "\n";
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

