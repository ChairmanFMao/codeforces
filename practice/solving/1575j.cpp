#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// I think that this might be brute force able

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int> > grid(n,vector<int>(m));
	for (vector<int>& i : grid)
		for (int& j : i)
			cin >> j;

	for (int i = 0; i < k; i++) {
		int start; cin >> start; start--;
		int x = start, y = 0;
		while (y < n) {
			if (grid[y][x] == 1) {
				grid[y][x] = 2;
				x++;
			} else if (grid[y][x] == 2)
				y++;
			else if (grid[y][x] == 3) {
				grid[y][x] = 2;
				x--;
			}
		}
		cout << x+1 << " ";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

