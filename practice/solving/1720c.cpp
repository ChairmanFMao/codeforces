#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int> > grid(n,vector<int>(m));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
			grid[i][j] = s[j] & 1;
	}

	int one = 0, zero = 3;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			one += grid[i][j];
			int current = grid[i][j];
			if (i && j)
				zero = min(current+grid[i-1][j]+grid[i][j-1],zero);
			if (i && j < m-1)
				zero = min(current+grid[i-1][j]+grid[i][j+1],zero);
			if (i < n-1 && j)
				zero = min(current+grid[i+1][j]+grid[i][j-1],zero);
			if (i < n-1 && j < m-1)
				zero = min(current+grid[i+1][j]+grid[i][j+1],zero);
		}
	}

	if (zero >= 2)
		one -= zero-1;
	cout << one << "\n";
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

