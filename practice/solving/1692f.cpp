#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

const int mxN = 2e5;
int dp[mxN+1][4][10];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)
		for (int k = 0; k < 4; k++)
			for (int j = 0; j < 10; j++)
				dp[i][k][j] = 0;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	dp[0][0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 10; k++) {
				dp[i+1][j][k] |= dp[i][j][k];
				if (j < 3)
					dp[i+1][j+1][(k+a[i])%10] |= dp[i][j][k];
			}
		}
	}

	cout << (dp[n][3][3] ? "YES" : "NO") << "\n";
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

