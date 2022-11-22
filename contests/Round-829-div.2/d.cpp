#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// I think this problem is chinese remainder theorem
// otherwise try to merge together the factorials or smth

const ll MOD = 1e9+7;

ll fastPow(ll base, ll exp) {
	ll out = 1;
	for(;exp;exp>>=1) {
		if (exp&1)
			out = (out * base) % MOD;
		base = (base * base) % MOD;
	}
	return out;
}

void solve() {
	ll n, x;
	cin >> n >> x;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	vector<ll> fact(500001,1), inv(500001,1);
	for (ll i = 1; i < sz(fact); i++) {
		fact[i] = (fact[i-1] * i) % MOD;
		inv[i] = fastPow(fact[i],MOD-2);
	}

	map<ll,ll> m;
	for (ll i : a)
		m[i]++;

	for (auto i = m.begin(); i != m.end(); i++) {
		if (i->s >= i->f+1) {
			m[i->f+1] += i->s/(i->f+1);
			m[i->f] %= (i->f + 1);
		}
		if (m[i->f] && (i->f < x)) {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

