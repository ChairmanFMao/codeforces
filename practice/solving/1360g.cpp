#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Just greedily generate it? If errors just exit
// wa on test 2 lol just implemented stuff wrong
// 17x17 grid with 13 on each row and column
// with new method getting wa on test 2 still

bool solve2(int n, int m, int a, int b, int add) {
	vector<vector<int> > grid(n, vector<int>(m,0));
	vector<int> row(n,0), column(m,0);
	int start = 0;
	for (int i = 0; i < n; i++) {
		int starts = start;
		while (column[start] >= b) {
			start = (start+1)%m;
			if (start == starts) {
				return 0;
			}
		}
		for (int j = start; j < start+m; j++) {
			if (row[i] < a && column[j%m] < b && !grid[i][j%m]) {
				grid[i][j%m] = 1;
				row[i]++;
				column[j%m]++;
			}
		}
		start = (start+add)%m;
	}

	for (int i : row)
		if (i != a) {
			return 0;
		}
	for (int i : column)
		if (i != b) {
			return 0;
		}

	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << grid[i][j];
		cout << "\n";
	}
	return 1;
}

void solve() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	
	for (int i = 0; i < 50; i++)
		if (solve2(n,m,a,b,i))
			return;

	cout << "NO\n";
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

