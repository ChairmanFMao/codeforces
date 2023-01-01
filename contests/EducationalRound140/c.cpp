#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// The value of n is very small, maybe dp or otherwise
// work from the back to the front with dp
// actually doing front to back might be easier
// potentially something O(n^3) idk
// unsure how to store history kinda or just do a better dp maybe?
// store the last streak of either 0 or 1 in a dimension and this
// can determine if its valid for some of them
// works for all the samples except the last one
// wa on test 13 somehow
// I just didn't take the modulo of the final output

const ll MOD = 998244353, mxN = 100;

void solve() {
	ll n;
	cin >> n;
	vector<vector<ll> > a(n);
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < n-i; j++) {
			ll tmp; cin >> tmp;
			a[i].push_back(tmp);
		}
	
	// First dimension stores how many seen
	// Second stores the last value
	// Third stores the streak
	// Value stores how many ways to get there
	vector<vector<vector<ll>> > dp(n+1,vector<vector<ll>>(2,vector<ll>(n+1,0)));
	/*
	for (ll i = 0; i <= n; i++) {
		dp[i][0][0] = 1;
		dp[i][1][0] = 1;
	}*/
	dp[0][0][0] = 1;

	// We are going to do push dp as I think it might be easier
	// I might reimplement this will pull as it would be better
	// from the front to back
	for (ll i = 1; i <= n; i++) {
		// Stores the type of rule and length
		vector<pair<ll,ll> > rules;
		// Adds all of the current rules
		for (ll j = 0; j < i; j++)
			// Only adds the rules if they aren't 0
			if (a[j][i-1-j])
				rules.push_back({a[j][i-1-j],i-j});

		/*
		cout << "rules: ";
		for (pair<ll,ll> j : rules)
			cout << j.f << " " << j.s << "  ";
		cout << "\n";
		*/

		// This iterates over the last character
		for (ll j = 0; j < 2; j++) {
			// This iterates over the new streak length
			for (ll k = 1; k <= n; k++) {
				// This iterates over the rules to check if it is
				// valid
				// dp[i-1][j][k-1]
				// We also need to cater for the switch
				// These store both values
				ll good = 1, good2 = 1;
				for (ll l = 0; l < sz(rules); l++) {
					if (rules[l].f == 1) {
						// This is the bad outcome
						if (rules[l].s > k)
							good = 0;
						if (rules[l].s > 1)
							good2 = 0;
					} else if (rules[l].f == 2) {
						// This is another bad outcome
						if (rules[l].s <= k)
							good = 0;
						if (rules[l].s <= 1)
							good2 = 0;
					}
				}
				if (good)
					dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k-1])%MOD;
				if (good2)
					dp[i][j^1][1] = (dp[i][j^1][1] + dp[i-1][j][k-1])%MOD;
				
			}
		}
	}

	ll out = 0;
	for (ll i = 0; i <= n; i++)
		for (ll j = 0; j < 2; j++)
			out = (out + dp[n][j][i])%MOD;

	/*
	for (ll i = 0; i <= n; i++) {
		for (ll j = 0; j < 2; j++) {
			for (ll k = 0; k <= n; k++) {
				cout << dp[i][j][k] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	*/

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

