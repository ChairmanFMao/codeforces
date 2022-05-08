#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// n is the cap for numbers we can use
// k is the length of the sequence we are making

const int mxN = 2e3, MOD = 1e9+7;
// The first dimension is for how many numbers seen
// The second dimension is for the last number
// The value is the number of ways to get there
ll dp[mxN+1][mxN+1];

void solve() {
	memset(dp, 0, sizeof dp);
	int n, k;
	cin >> n >> k;

	dp[0][1] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			for (int m = j; m <= n; m+=j) {
				dp[i][m] = (dp[i][m] + dp[i-1][j]) % MOD;
			}
		}
	}

	ll out = 0;
	for (int i = 0; i <= n; i++)
		out = (out + dp[k][i]) % MOD;

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

