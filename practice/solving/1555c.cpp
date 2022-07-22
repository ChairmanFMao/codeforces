#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

const int mxM = 1e5;
int grid[2][mxM], prefix[2][mxM+1];

void solve() {
	memset(prefix, 0, sizeof prefix);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> grid[0][i];
	for (int i = 0; i < m; i++)
		cin >> grid[1][i];

	int total1 = 0, total2 = 0;
	for (int i = 1; i <= m; i++) {
		total1 += grid[0][i-1];
		total2 += grid[1][i-1];
		prefix[0][i] = total1;
		prefix[1][i] = total2;
	}

	int out = INT_MAX;
	for (int i = 0; i < m; i++) {
		int bot = prefix[1][i] - prefix[1][0];
		int top = prefix[0][m] - prefix[0][i+1];
		out = min(out,max(top,bot));
	}
	
	cout << out << "\n";
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

