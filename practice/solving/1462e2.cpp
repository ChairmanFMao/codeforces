#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

const ll MOD = 1e9+7, mxN = 2e5+1;
ll fact[mxN], invFact[mxN];

// I think that this problem is a dp one
// I think my solution might be O(n * m * n * n)
// In each state, number seen, number done, max, min
// time limit is 4 seconds for this problem
// store number smaller later in array and get O(n)?
// not possible to brute force all cases
// looked at some comments and had an idea
// should've known some of this stuff from encryption
// however, I didn't recognise it.
// Ended up using the editorial kinda heavily but I learnt
// a bit more about inverse factorial with a mod

ll power(ll base, ll exp) {
	ll out = 1;
	base %= MOD;
	for (; exp > 0; exp>>=1) {
		if (exp&1)
			out = (out * base) % MOD;
		base = (base * base) % MOD;
	}

	return out;
}

ll choose(ll n, ll k) {
	if (k > n)
		return 0;
	return (fact[n] * ((invFact[k] * invFact[n-k]) % MOD)) % MOD;
}

void solve() {
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	sort(all(a));
	ll out = 0;
	for (int i = 0; i < n; i++) {
		int left = i+1;
		int right = upper_bound(all(a), a[i] + k) - a.begin();
		out = (out + choose(right - left, m - 1)) % MOD;
	}

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	fact[0] = invFact[0] = 1;
	for (ll i = 1; i < mxN; i++) {
		fact[i] = (fact[i-1] * i) % MOD;
		// Multiplying by invFact is the same as dividing by
		// the factorial and doing the modulo
		// Euler's totient function
		invFact[i] = power(fact[i], MOD-2);
	}
	
	cout << "\n";
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

