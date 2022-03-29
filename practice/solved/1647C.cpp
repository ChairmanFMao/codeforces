#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Very small constraints, t = 1-10
// No more than n*m operations, don't need to minimise operations
// This worked quite nicely :)

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<bool> > grid(n, vector<bool>(m));
	string s;
	int operations = 0;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			grid[i][j] = stoi(s.substr(j,1));
			operations += stoi(s.substr(j,1));
		}
	}
	
	// This is the only thing that is impossible
	if (grid[0][0]) {
		cout << "-1\n";
		return;
	}
	
	cout << operations << "\n";
	// Iterate backwards from the bottom right corner
	for (int i = n-1; i >= 0; i--) {
		for (int j = m-1; j >= 0; j--) {
			if (grid[i][j]) {
				if (!i)
					cout << i+1 << " " << j << " " << i+1 << " " << j+1 << "\n";
				else
					cout << i << " " << j+1 << " " << i+1 << " " << j+1 << "\n";
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

