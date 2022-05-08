#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n, m;
	string s;
	cin >> n >> m;
	vector<vector<int> > grid(n, vector<int> (m));
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++)
			grid[i][j] = s[j] == '*' ? 1 : s[j] == '.' ? 0 : 2;
	}

	for (int i = 0; i < m; i++) {
		for (int j = n-1; ~j; j--) {
			if (grid[j][i] == 1) {
				int start = j+1;
				while (start < n && grid[start][i] == 0)
					start++;
				start--;
				grid[j][i] = 0;
				grid[start][i] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << (grid[i][j] == 0 ? '.' : grid[i][j] == 1 ? '*' : 'o');
		cout << "\n";
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

