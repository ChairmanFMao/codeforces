#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// This is probably some dp sorta thing
// it will be quite difficult as 2^n is very large
// I can think of an O(n k) dp but it will be too slow
// maybe this is actually some kind of combinatorics
// if you have one that only uses the first m bits then
// all of the other ones can be turned on and off, 3^(n-m) ways
// get the number of ways from lowest to highest bits
// I wanna try doing the O(n k) solution
// also need to store if previous had a carry bit onto the next
// if there isn't a carry:
// 3 ways to keep carry the same
// 1 way to increase carry
// if there is a carry:
// 1 way to keep carry the same
// 3 ways to increase carry
// we need a logarithmic factor somehow I think
// this is kinda the only way to pass the constraints
// maybe we need to decompose numbers into primes?
// I think when doing O(n k) we can drop some of the bits as we
// progress as we know that they will not result in anything
// however I don't think this time gain will be enough
// what if we just precalculated and stored everything?
// this might not run fast enough as 1e12 operations is too many
// even using this dp is a bit sketchy
// it is not possible to get O(n k) to pass
// there are 3^leftover ways if you have one that works
// to get k carries you need 1 1 with 1 0 or better after
// and then 1 1 to all sum to k
// just need to place all of them within n bits
// each of the streaks can be configured in 3^(l-1) ways
// there should also be gaps between the blocks of at least 1
// the rest would have (space-1)*3^(n-number) ways
// then it could just be combinatorics?
// so just 3^(n-blocks) ways, when block lengths sum to k
// more than just that as can have a block at the end with 1 less
// length
// add blocks*3^(n-blocks+1)
// I don't know the best way of doing this
// even with the dp I think that I still end up with O(n^2)
// This might even lead to O(n^2 ln n)
// if I can remove a factor of n this will work
// It is actually O(n^3) and I don't think there is an easy way
// to optimise it.
// also doing the choose function will be a hastle
// managed to get the O(n k) solution to work
// after fixing the mle issue, it gets tle

const ll MOD = 1e9+7;

void solve() {
	ll n, k;
	cin >> n >> k;

	vector<vector<vector<ll>> > dp(2,vector<vector<ll>>(k+1,vector<ll>(2,0)));
	dp[0][0][0] = 1;
	for (ll i = 0; i < n; i++) {
		ll o = (i&1)^1, c = i&1;
		for (ll j = 0; j <= k; j++) {
			if (j < k)
				dp[o][j+1][1] = (dp[c][j][0] + 3*dp[c][j][1])%MOD;
			dp[o][j][0] = (3*dp[c][j][0] + dp[c][j][1])%MOD;
		}
	}

	cout << (dp[n&1][k][0]+dp[n&1][k][1])%MOD << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

