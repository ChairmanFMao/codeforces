#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

const ll MOD = 1e9+7;

// Want 1 vs 2 in final
// need to find the spots were the swaps would be worst
// then somehow work backwards to make them better
// The winners of all the matches are set already
// the sponsors can just swaps two values basically
// misinterpreted the question
// wa on pretest 4, unsure of edge case
// power and modular inverse work fine
// maybe there is a flaw in my approach?
// there is a case where: 3 1 -> 4 if engineered right
// something to do with divisibility by 8, idk?
// I literally did this earlier in the day ;-;
// Should've realised it was the choose function

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

void solve() {
	ll n, k;
	cin >> n >> k;

	vector<ll> fact(n+1,0), invFact(n+1,0);
	fact[0] = invFact[0] = 1;
	for (ll i = 1; i <= n; i++) {
		fact[i] = (fact[i-1] * i) % MOD;
		invFact[i] = power(fact[i], MOD-2);
	}

	ll out = 0;
	for (ll i = 0; i <= min(n,k); i++)
		out = (out+(((fact[n] * invFact[n-i])%MOD) * invFact[i])%MOD) % MOD;

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

