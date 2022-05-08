#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

const int mxN = 1e3, MOD = 1e9+7;

ll dp[mxN+1][mxN+1];

void solve() {
	int n, m;
	cin >> n >> m;
	memset(dp, 0, sizeof dp);
	
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD;
			dp[i][j+1] = (dp[i][j+1] + dp[i][j]) % MOD;
		}
	}

	cout << dp[n-1][m-1] << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

