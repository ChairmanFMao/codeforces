#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<bool> > grid(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
			grid[i][j] = (s[j] == 'R');
	}
	int leftmost = 1e9, highest = 1e9;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j < leftmost && grid[i][j])
				leftmost = j;
			if (i < highest && grid[i][j])
				highest = i;
		}
	}

	cout << (grid[highest][leftmost] ? "YES" : "NO") << "\n";
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

