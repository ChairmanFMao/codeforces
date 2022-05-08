#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Cubic time complexity would timeout
// Need 3 displays that strictly increase in font size
// We want to minimize the cost of these displays
// 3 <= n <= 3000, so maybe dp over n?
// maybe make font size relative and then dp over it
// wa on test 6, currently overshooting answer
// I think it was just on line 56 where I was using < rather than <=
// Epicly accepted
// Just did a little optimisation to reduce the size of dp
// Vastly decreased memory usage and also time reduced as well

const int mxN = 3e3, INF = 1e9;
// First dimension is for number of displays seen
// Second dimesion is for the number of displays bought
// Third dimension is for the current size
// Value is for the cost to get to that point
int dp[2][4][mxN+2];

void solve() {
	// This sets up dp
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k <= mxN+1; k++)
				dp[i][j][k] = INF;

	int n;
	cin >> n;
	vector<int> s(n), c(n);
	for (int& i : s)
		cin >> i;
	for (int& i : c)
		cin >> i;

	// This code makes all of s relative so we don't need a big dp array
	set<int> u(all(s));
	vector<int> unique(all(u));
	sort(all(unique));
	map<int,int> relative;
	for (int i = 0; i < sz(unique); i++)
		relative[unique[i]] = i+1;
	for (int i = 0; i < n; i++)
		s[i] = relative[s[i]];

	// This sets all of the first row of dp to zero
	for (int i = 0; i <= mxN+1; i++)
		dp[0][0][i] = 0;

	// This is the value we are currently processing
	for (int i = 1; i <= n; i++) {
		// This is the number of displays bought
		for (int j = 0; j < 4; j++) {
			// This is the size of the font
			for (int k = 0; k <= sz(unique); k++) {
				// This is if a purchase isn't made
				dp[i&1][j][k] = min(dp[i&1][j][k], dp[(i&1)^1][j][k]);
				// This is if a purchase is made
				if (s[i-1] > k && j < 3 && dp[(i&1)^1][j][k] < INF)
					dp[i&1][j+1][s[i-1]] = min(dp[i&1][j+1][s[i-1]], dp[(i&1)^1][j][k] + c[i-1]);
			}
		}
	}

	int out = INF;
	for (int i = 0; i <= mxN+1; i++)
		out = min(out, dp[n&1][3][i]);

	cout << (out == INF ? -1 : out) << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

