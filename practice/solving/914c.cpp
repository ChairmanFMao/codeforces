#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// something about bitwise operations
// maybe store the with dp kinda, perhaps a map
// somehow need to elimate all above a certain range
// just need to calculate for totals up to 1000
// need to find how many ways that total can be made
// can get all less than (n/2) * 2, unsure about rest
// just deal with the last bit some other way
// once you find the first 1 it can be converted
// it gets really messy at the end
// dp the totals from left to right?
// need to get the dp transitions right
// might need to make another dimension for if concession made
// currently overestimates by a lot
// might only need one dimension actually
// looked at editorial
// I also looked at benq's code and this is the dp that i
// was trying to do

const ll MOD = 1e9+7;
ll dp[2][1001][1001];

void solve() {
	string s;
	ll k;
	cin >> s >> k;
	ll n = sz(s);

	if (k == 0) {
		cout << "1\n";
		return;
	}

	vector<ll> ops(1001,0);
	for (int i = 2; i <= 1000; i++)
		ops[i] = ops[__builtin_popcount(i)]+1;

	string s2 = "";
	for (int i = 0; i < 1000-n; i++)
		s2 += "0";
	s = s2 + s;

	dp[1][0][0] = 1;
	for (ll i = 0; i < 1000; i++) {
		for (ll j = 0; j < i+1; j++) {
			for (ll k = 0; k < 2; k++) {
				dp[k][i][j] %= MOD;
				if (k == 0) {
					dp[k][i+1][j+1] = (dp[k][i+1][j+1]+dp[k][i][j])%MOD;
					dp[k][i+1][j] = (dp[k][i+1][j]+dp[k][i][j])%MOD;
				} else {
					if (s[i] == '0') {
						dp[k][i+1][j] = (dp[k][i+1][j]+dp[k][i][j])%MOD;
					} else {
						dp[0][i+1][j] = (dp[0][i+1][j]+dp[k][i][j])%MOD;
						dp[k][i+1][j+1] = (dp[k][i+1][j+1]+dp[k][i][j])%MOD;
					}
				}
			}
		}
	}

	for (int i = 0; i < 1001; i++)
		dp[0][1000][i] = (dp[0][1000][i]+dp[1][1000][i])%MOD;
	dp[0][1000][1] = (dp[0][1000][1] + MOD-1)%MOD;

	ll out = 0;
	for (ll i = 1; i < 1001; i++)
		if (ops[i] == k-1)
			out = (out + dp[0][1000][i])%MOD;

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

