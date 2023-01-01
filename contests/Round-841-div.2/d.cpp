#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Like a 2d binary search for each square
// is it a forest query thing?
// size of l*l and all elements greater than l
// just get the min of two squares for each of the values
// storing tmp values will be very difficult
// might be way in O(nm*log l)
// binary search over l
// there was also just a geeks for geeks article on this problem
// I had the correct idea, I just didn't implement it properly

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<vector<ll> > grid(n,vector<ll>(m));
	for (vector<ll>& i : grid)
		for (ll& j : i)
			cin >> j;

	vector<vector<ll> > grid2(n,vector<ll>(m));
	vector<vector<ll> > grid3(n,vector<ll>(m));
	vector<vector<ll> > grid4(n,vector<ll>(m));
	vector<vector<ll> > grid5(n,vector<ll>(m));
	
	ll lower = 1, upper = 1e6+1, mid = 0, pl = -1, pu = -1;
	while (lower <= upper) {
		if (lower == pl && upper == pu)
			break;

		mid = (lower+upper)>>1;
		for (ll i = 0; i < n; i++)
			for (ll j = 0; j < m; j++) {
				grid2[i][j] = grid[i][j] >= mid ? 1 : 0;
				if (!i || !j)
					grid3[i][j] = grid2[i][j];
			}

		for (ll i = 1; i < n; i++)
			for (ll j = 1; j < m; j++)
				grid3[i][j] = grid2[i][j] ? min({grid3[i][j-1],grid3[i-1][j],grid3[i-1][j-1]})+grid2[i][j] : 0;

		ll out = 0;
		for (ll i = 0; i < n; i++)
			for (ll j = 0; j < m; j++)
				out = max(out,grid3[i][j]);

		pl = lower; pu = upper;
		if (out >= mid)
			lower = mid;
		else
			upper = mid;
	}

	cout << lower << "\n";
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

