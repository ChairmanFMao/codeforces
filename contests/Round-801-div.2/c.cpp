#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

const int mxN = 1e3;
int n, m;
vector<vector<int> > grid(mxN, vector<int>(mxN));
int dp1[mxN+1][mxN+1], dp2[mxN+1][mxN+1];


void solve() {
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++) {
			if (i < n && j < m)
				cin >> grid[i][j];
			dp1[i][j] = 0;
			dp2[i][j] = 0;
		}

	for (int i = n-1; ~i; i--) {
		for (int j = m-1; ~j; j--) {
			dp1[i][j] = max(dp1[i+1][j], dp1[i][j+1]);
			if (grid[i][j] == 1)
				dp1[i][j]++;

			dp2[i][j] = max(dp2[i+1][j], dp2[i][j+1]);
			if (grid[i][j] == -1)
				dp2[i][j]++;
		}
	}
	
	if ((m+n-1) & 1) {
		cout << "NO\n";
	} else {
		int val = (m+n-1)/2;
		cout << (dp1[0][0] >= val && dp2[0][0] >= val ? "YES" : "NO") << "\n";
	}
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

