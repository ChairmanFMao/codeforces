#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

const int mxN = 50;
bool grid[mxN][mxN], valid[mxN][mxN], seen[mxN][mxN];
int n;

vector<pair<int, int> > movement = {{-1,0},{0,-1}};

void dfs(int y, int x) {
	if (y >= n || x >= n || x < 0 || y < 0 || seen[y][x])
		return;

	seen[y][x] = 1;
	if (grid[y][x])
		valid[y][x] = 1;
	else
		return;
	
	for (pair<int,int> i : movement)
		dfs(y + i.first, x + i.second);
}

void solve() {
	memset(valid, 0, sizeof valid);
	memset(seen, 0, sizeof seen);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
			grid[i][j] = (s[j] & 1);
	}
	
	for (int i = 0; i < n; i++) {
		if (grid[i][n-1])
			dfs(i,n-1);
		if (grid[n-1][i])
			dfs(n-1,i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!valid[i][j] && grid[i][j]) {
				cout << "NO\n";
				return;
			}
		}
	}
	
	cout << "YES\n";
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

