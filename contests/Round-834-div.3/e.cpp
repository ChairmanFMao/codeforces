#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// I think that greedy might even work here
// better to multiply by 3 if possible
// wa on test 3
// might be nice to do with dp

ll fastPow(ll base, ll exp) {
	ll out = 1;
	for (;exp;exp>>=1) {
		if (exp&1)
			out *= base;
		base *= base;
	}
	return out;
}

void solve() {
	ll n, h;
	cin >> n >> h;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	sort(all(a));
	vector<vector<vector<ll> > > dp(n+1,vector<vector<ll>>(3,vector<ll>(2,-1e15)));
	dp[0][2][1] = h;
	for (ll i = 1; i <= n; i++) {
		// Iterates over the dimensions
		for (ll j = 0; j < 3; j++) {
			for (ll k = 0; k < 2; k++) {
				// Iterates over how many to use
				if (dp[i-1][j][k] == -1e15)
					continue;
				for (ll l = 0; l <= j; l++) {
					for (ll m = 0; m <= k; m++) {
						if (dp[i-1][j][k] * fastPow(2,l) * fastPow(3,m) > a[i-1] || a[i-1] == 1) {
							dp[i][j-l][k-m] = max(dp[i][j-l][k-m],dp[i-1][j][k] * fastPow(2,l) * fastPow(3,m) + a[i-1]/2);
						}
					}
				}
			}
		}
	}

	ll out = 0;
	//cout << "dp\n";
	for (ll i = 0; i <= n; i++) {
		for (ll j = 0; j < 3; j++) {
			for (ll k = 0; k < 2; k++) {
				if (!(dp[i][j][k]==-1e15))
					out = max(i,out);
				//cout << dp[i][j][k] << " ";
			}
			//cout << "\n";
		}
		//cout << "\n\n";
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

