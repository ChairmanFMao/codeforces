#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

const int mxN = 1e2, mxA = 1e4;

int dp[mxN+1][mxA+1];

void solve() {
	memset(dp, 0, sizeof dp);
	int n, t;
	cin >> n >> t;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	dp[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= mxA; j++) {
			dp[i][j] |= dp[i-1][j];
			if (j+a[i-1] <= mxA)
				dp[i][j+a[i-1]] |= dp[i-1][j];
		}
	}

	cout << (dp[n][t] ? "YES" : "NO") << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

