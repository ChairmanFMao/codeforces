#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Need to get all the quadrants to become equal

void solve() {
	int n;
	cin >> n;
	vector<vector<int> > grid(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
			grid[i][j] = s[j] & 1;
	}

	// counts the number of 1 in each spot
	vector<vector<int> > rotates(n, vector<int>(n,0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			rotates[i][j] += grid[i][j];
			rotates[j][i] += grid[n-1-i][j];
			rotates[i][j] += grid[n-1-i][n-1-j];
			rotates[j][i] += grid[i][n-1-j];
		}

	int out = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			out += min(rotates[i][j], 4-rotates[i][j]);

	cout << out/4 << "\n";
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

