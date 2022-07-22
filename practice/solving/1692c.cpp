#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

vector<vector<bool> > grid(8,vector<bool>(8));

bool check(int i, int j) {
	bool out = grid[i][j];
	out &= grid[i+1][j+1];
	out &= grid[i+1][j-1];
	out &= grid[i-1][j+1];
	out &= grid[i-1][j-1];
	return out;
}

void solve() {
	for (int i = 0; i < 8; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 8; j++)
			grid[i][j] = s[j] == '#';
	}

	for (int i = 1; i < 7; i++) {
		for (int j = 1; j < 7; j++) {
			if (check(i,j)) {
				cout << i+1 << " " << j+1 << "\n";
				return;
			}
		}
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

