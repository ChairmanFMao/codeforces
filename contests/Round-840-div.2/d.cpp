#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

const ll MOD = 1e9+7;

// This is just dynamic programming I think
// Just make it increasing until k and then there is only 1 way
// store how many seen and what the prior max is
// Bi is x and Bj is y
// this makes it more difficult
// I think that this is easier than c
// need to store how many seen as well
// we just have to set some elements
// unsure too keep track of how many seen efficiently
// we know that the max element occurs at index k we aren't told k
// could just store the number greater and less than x and y
// In transitions we can either decrease both or just the one with
// the higher number, we need there to be n-j smaller than y when
// we reach index j

void solve() {
	ll n, i, j, x, y;
	cin >> n >> i >> x >> j >> y;

	// First stores how many seen
	// Second stores how many less than x left
	// Third store how many less than y left
	// Value is how many ways to get there
	vector<vector<vector<ll> > > dp(n+1,vector<vector<ll>>(n+1,vector<ll>(n+1,0)));
	ll lessx = 0, lessy = 0;
	for (ll i = 1; i <= n; i++) {
		if (i == x || i == y)
			continue;
		if (i < x)
			lessx++;
		if (i < y)
			lessy++;
	}

	// This is the base case
	dp[0][lessx][lessy] = 1;
	// I think I will use push dp
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			for (ll k = 0; k < n; k++) {

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

