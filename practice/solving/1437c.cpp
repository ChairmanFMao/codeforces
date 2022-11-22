#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Minimum unpleasant value
// I think something to do with dp due to the
// low bounds, n <= 200 and q <= 200
// unsure if you should wait if there is a gap
// max unpleasant is like 40000 ish
// dp with state for seen, state for time
// Times range from 0 to 400
// the value for current is only 200
// always best to take the items out in sorted
// order
// currently works for all test cases except the
// last one where it underestimates

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	sort(all(a));
	// First dimension is for time
	// Second dimension is for how many taken
	// Value is for the min unpleasantness
	vector<vector<ll> > dp(402, vector<ll>(n+1,INT_MAX));

	dp[0][0] = 0;
	// This iterates the time
	for (ll i = 0; i <= 400; i++) {
		// This iterates which one is taken
		for (ll j = 0; j < n; j++) {
			// This just transfers the current state to one later with a greater time
			dp[i+1][j] = min(dp[i][j], dp[i+1][j]);
			// This checks to see if taking out the current one is a beneficial move
			dp[i+1][j+1] = min(dp[i][j] + abs(a[j]-i-1), dp[i+1][j+1]);
		}
	}

	ll out = INT_MAX;
	for (int i = 0; i <= 401; i++)
		out = min(out, dp[i][n]);

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

