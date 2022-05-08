#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

const int mxN = 1e5, MOD = 1e9+7;

ll dp[mxN+3];

void solve() {
	memset(dp, 0, sizeof dp);
	int n;
	cin >> n;

	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		dp[i+1] = (dp[i+1] + dp[i]) % MOD;
		dp[i+2] = (dp[i+2] + dp[i]) % MOD;
	}

	cout << dp[n] << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

