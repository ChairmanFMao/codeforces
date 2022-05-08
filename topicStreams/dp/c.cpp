#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Cubic time complexity would lead to timeout
// My solution here got TLE, with early exit it passes just
// Wrote better solution after looking at video
// We dp over n and we can incrementally keep the best totals
// I made it better so that it only uses dp with depth of 2
const int mxN = 1e3, INF = 1e9;
int dp[2][8];

void solve() {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 8; j++)
			dp[i][j] = INF;
	int n;
	cin >> n;
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		int b;
		string s;
		cin >> b >> s;
		int current = 0;
		for (char c : s) {
			if (c == 'A')
				current |= 1;
			if (c == 'B')
				current |= 2;
			if (c == 'C')
				current |= 4;
		}

		for (int j = 0; j < 8; j++) {
			dp[(i&1)^1][j] = min(dp[(i&1)^1][j], dp[i&1][j]);
			dp[(i&1)^1][current|j] = min(dp[(i&1)^1][current|j], dp[i&1][j] + b);
		}
	}

	cout << (dp[n&1][7] == INF ? -1 : dp[n&1][7]) << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

