#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n;
	string s;
	cin >> n >> s;

	// 0 means X, 1 is for +, 2 is for -, 3 is for =
	vector<vector<int> > grid(n,vector<int>(n,0));
	vector<int> flag(n,0);
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if ((s[i] & 1) || (s[j] & 1)) {
				grid[i][j] = 3;
				grid[j][i] = 3;
			} else if (!flag[i] && (s[i] % 2 == 0)) { 
				grid[i][j] = 1;
				grid[j][i] = 2;
				flag[i] = 1;
			} else if (s[j] % 2 == 0) {
				grid[i][j] = 2;
				grid[j][i] = 1;
				flag[j] = 1;
			} else {
				grid[i][j] = 3;
				grid[j][i] = 3;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int out = s[i]&1, flag = 0;
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			if (s[i] & 1)
				out &= grid[i][j];
			else if (grid[i][j] == 1)
				flag = 1;
		}
		if (s[i] & 1) {
			if (out % 2 == 0) {
				cout << "NO\n";
				return;
			}
		} else {
			if (!flag) {
				cout << "NO\n";
				return;
			}
		}
	}

	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << (grid[i][j] == 0 ? 'X' : grid[i][j] == 1 ? '+' : grid[i][j] == 2 ? '-' : '=');
		}
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

