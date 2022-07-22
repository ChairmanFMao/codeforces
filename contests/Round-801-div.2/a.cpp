#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int> > grid(n, vector<int> (m));
	for (vector<int>& i : grid)
		for (int& j : i)
			cin >> j;

	pair<int,int> big = {0,0};
	int biggest = INT_MIN;
	for (int i = 0; i < n; i++)  {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] > biggest) {
				biggest = grid[i][j];
				big = {i,j};
			}
		}
	}
	int x = max(big.first+1, n-big.first);
	int y = max(big.second+1, m-big.second);

	cout << x*y << "\n";
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

