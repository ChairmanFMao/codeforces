#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Now getting wa on test 3, part 333 for some reason
// Unsure why all of my values are doubled for some reason
//
// This finally gets accepted!

const int MOD = 998244353, mxK = 650, mxN = 2e5;

void solve() {
	int n, k;
	cin >> n >> k;

	// First dimension is for the total
	// Second dimension is for how many k used
	// Actual value is for how many ways
	vector<vector<ll>> dp(2,vector<ll>(mxN+1,0));
	vector<ll> out(mxN+1,0);
	dp[0][0] = 1;
	
	for (int j = 0; j < mxK; j++) {
		for (int i = 0; i < n; i++) {
			if (i+k+j > n)
				continue;
			dp[j&1][i+k+j] = (dp[j&1][i+k+j] + dp[j&1][i]) % MOD;
			dp[(j&1)^1][i+k+j] = (dp[(j&1)^1][i+k+j] + dp[j&1][i]) % MOD;
		}

		for (int i = 0; i <= n; i++) {
			if (i)
				out[i] = (out[i] + dp[j&1][i]) % MOD;
			dp[j&1][i] = 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (out[i] & 1)
			out[i] = ((out[i] + MOD)/2)%MOD;
		else
			out[i] /= 2;

		cout << out[i] << " ";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

