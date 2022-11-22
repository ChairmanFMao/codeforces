#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

const ll MOD = 998244353;
// definitly dp of a kind
// smth like combinatorics maybe?
// all 1 is always a valid removal sequence
// just need to find another removal sequence for each
// factorial values will be needed
// all of the elements are shifted after
// this can be resolved by just doing one operation then all 1
// we are now overcounting due to there being multiple combos done
// twice
// what if we store a coprime factorial and do mod inverse
// number of combos before which involve coprime numbers
// getting a lot closer now, slightly underestimating
// select a coprime number from before, select a current divisor
// and select either later
// can get others where it triggers after some removal
// length from 1 to n, prefix sum with fastPow I think
// just need one divisible one later in the array
// all of the ones after need to be factors for it to work

bool prime(ll a) {
	if (a==2) return 1;
	if (a==1||!(a&1)) return 0;
	for (ll i = 3; i*i <= a; i+=2)
		if (!(a%i))
			return 0;
	return 1;
}

ll fastPow(ll base, ll exp) {
	base %= MOD;
	ll out = 1;
	for (;exp;exp>>=1) {
		if (exp&1)
			out = (out * base)%MOD;
		base = (base * base)%MOD;
	}
	return out;
}

void solve() {
	ll n, m;
	cin >> n >> m;

	ll out = 0, bad = m%MOD, primeProduct = 1;
	for (ll i = 2; i <= n; i++) {
		// Store the product of all the primes so far
		if (primeProduct <= m && prime(i))
			primeProduct *= i;
		// Gets the total number of ways can be made
		out = (out + fastPow(m,i)) % MOD;
		// Gets the non ambiguous sequences
		// Gets the total number of numbers that will satisfy
		// the conditions with a factorial of a kind
		bad = (bad*((m/primeProduct)%MOD))%MOD;
		out -= bad;
		if (out < 0)
			out += MOD;
	}

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

