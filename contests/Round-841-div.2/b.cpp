#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Just like the choose function kinda
// This is not possible with dp as n is very large
// we want something logarithmic or better
// there is probably a formula for this
// they want the max number of dogs not the number of ways
// number of dogs is i*j
// can only go right and down
// we could kinda do this recursively
// square numbers + square number+1
// I think that there will just be a formula for this
// not twice the sum of the squares
// now we just need to add in the modulo

const ll MOD = 1e9+7;

ll fastPow(ll base, ll exp) {
	ll out = 1;
	for (;exp;exp>>=1) {
		if (exp&1)
			out = (out*base)%MOD;
		base = (base*base)%MOD;
	}
	return out;
}

void solve() {
	ll n;
	cin >> n;

	ll out = 0;
	ll tmp = (((n*(n+1))%MOD)*fastPow(2,MOD-2))%MOD;
	out = ((2*((tmp*(n+n+1))%MOD))*fastPow(3,MOD-2))%MOD + tmp%MOD;
	out = (out - tmp*2)%MOD;
	while (out < 0)
		out = (out + MOD)%MOD;
	
	cout << (2022*out)%MOD << "\n";
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

