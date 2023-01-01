#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

ll grid[2][2];
void solve() {
	cin >> grid[0][0] >> grid[0][1] >> grid[1][0] >> grid[1][1];

	for (ll i = 0; i < 4; i++) {
		if (grid[0][0] < grid[0][1] && grid[1][0] < grid[1][1] && grid[0][0] < grid[1][0] && grid[0][1] < grid[1][1]) {
			cout << "YES\n";
			return;
		}
		vector<ll> t(4);
		t[0] = grid[0][0];
		t[1] = grid[0][1];
		t[2] = grid[1][0];
		t[3] = grid[1][1];
		grid[0][0] = t[2];
		grid[0][1] = t[0];
		grid[1][0] = t[3];
		grid[1][1] = t[1];
	}
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

