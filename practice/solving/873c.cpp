#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Just do a brute force?
// Each column can be dealt with independently

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int> > grid(n, vector<int>(m));
	for (vector<int>& i : grid)
		for (int& j : i)
			cin >> j;

	int out = 0, moves = 0;
	for (int i = 0; i < m; i++) {
		int current = 0, currentCost = 0, best = 0, cost = 0;
		for (int j = 0; j < min(n,k); j++)
			current += grid[j][i];

		for (int j = 0; j < n; j++) {
			if (grid[j][i]) {
				if (current > best) {
					best = current;
					cost = currentCost;
				}
				currentCost++;
				current--;
			}
			if (j+k < n)
				current += grid[j+k][i];
		}
		out += best;
		moves += cost;
	}

	cout << out << " " << moves << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

