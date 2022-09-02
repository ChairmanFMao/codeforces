#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// any sub table of 1xk or kx1
// kinda just offset from the set one

void solve() {
	int n, k, r, c;
	cin >> n >> k >> r >> c; r--; c--;
	
	vector<vector<int> > grid(n, vector<int>(n,0));
	for (int i = c%k; i < n; i+=k)
		grid[r][i] = 1;
	int c2 = c;
	for (int i = 1; i <= r; i++) {
		c2--;
		if (c2 < 0)
			c2 += n;
		for (int j = c2%k; j < n; j+=k)
			grid[r-i][j] = 1;
	}
	int c3 = c;
	for (int i = 1; i < n-r; i++) {
		c3++;
		if (c3 >= n)
			c3 -= n;
		for (int j = c3%k; j < n; j+=k)
			grid[r+i][j] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << (grid[i][j] ? 'X' : '.');
		cout << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

