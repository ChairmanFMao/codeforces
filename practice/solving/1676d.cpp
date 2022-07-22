#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

const int mxN = 2e2;
int n, m;

int grid[mxN][mxN];

int process(int x, int y) {
	int out = grid[x][y];
	for (int i = 1; i < n; i++) {
		if (x + i < n && y + i < m)
			out += grid[x+i][y+i];
		if (x + i < n && y - i >= 0)
			out += grid[x+i][y-i];
		if (x - i >= 0 && y + i < m)
			out += grid[x-i][y+i];
		if (x - i >= 0 && y - i >= 0)
			out += grid[x-i][y-i];
	}
	return out;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> grid[i][j];

	int out = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			out = max(out,process(i,j));

	cout << out << "\n";
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

