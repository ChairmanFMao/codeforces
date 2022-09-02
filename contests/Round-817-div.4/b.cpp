#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n;
	cin >> n;
	vector<vector<int> > grid(2, vector<int>(n));
	for (int i = 0; i < 2; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < sz(s); j++)
			grid[i][j] = s[j] == 'R' ? 0 : 1;
	}

	cout << (grid[0] == grid[1] ? "YES" : "NO") << "\n";
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

