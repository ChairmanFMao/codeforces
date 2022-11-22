#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

const ll MOD = 998244353;

// something with dp
// There are a lot of ways to make p and q, unsure what dp to do
// if at index i there are (i-1)^2 * (n-i)^2 pairs with other
// just noticed, p in increasing order and q in decreasing order
// n moves and each one would take constant time I think
// Need to find number of ways other ones can match up
// I think that this could be done better with pointers
// looked at editorial
// its actually the choose fuction and the order doesn't matter
// did some cool stuff with binary exponentiation and modular
// inverse to get everything to work

vector<ll> fact(3e5+1,1);

ll fastpow(ll base, ll exp) {
	ll out = 1;
	for (;exp;exp>>=1) {
		if (exp&1)
			out = (out * base)%MOD;
		base = (base * base)%MOD;
	}
	return out;
}

ll choose(ll n, ll k) {
	ll out = fact[n];
	out = (out * fastpow(fact[k],MOD-2))%MOD;
	out = (out * fastpow(fact[n-k],MOD-2))%MOD;
	return out%MOD;
}

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n+n);
	for (ll& i : a)
		cin >> i;

	sort(all(a));
	vector<int> b,c;
	for (int i = 0; i < n+n; i++) {
		if (i < n)
			b.emplace_back(a[i]);
		else
			c.emplace_back(a[i]);
	}

	reverse(all(c));

	ll out = 0;
	for (int i = 0; i < sz(b); i++)
		out += abs(b[i]-c[i]);

	out %= MOD;
	cout << (out * choose(n+n,n)) % MOD << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for (int i = 1; i < 3e5+1; i++)
		fact[i] = (fact[i-1] * i)%MOD;
	solve();
}

