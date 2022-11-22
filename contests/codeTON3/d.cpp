#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

const ll MOD = 998244353, mxN = 2e5;

// One of the elements must be a[i] at least
// I think that this method might be O(n^2) sadly
// there is also overlap between numbers
// do it for all of a that are coprime with each other?
// actually doing this would also be O(n^2)
// Didn't read question properly lol
// the gcd of the prefix from 1 to i needs to be ai
// the values of b are capped at m
// prime factorisation + working backwards?
// find out what factor needs to be added for each one
// hasn't appeared in at least 1 number before
// any combination of the factors must be catered for
// double counted the thirds and all that
// tle on test case 10
// passed and it was because of this silly if statement I had

ll cur = 0;

void dfs2(vector<ll>& extra, ll pos, ll length, ll desired, ll tot, ll times, ll m) {
	if (length == desired) {
		cur += m/(tot*times);
		return;
	}
	for (ll i = pos; i < sz(extra); i++)
		dfs2(extra,i+1,length+1,desired,tot*extra[i],times,m);
}

ll dfs(vector<ll>& extra, ll length, ll times, ll m) {
	cur = 0;
	dfs2(extra,0,0,length,1,times,m);
	return cur;
}

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	// This does a quick check to validate all of a
	for (ll i = 0; i < n-1; i++)
		if (a[i] % a[i+1]) {
			cout << "0\n";
			return;
		}

	ll out = 1;
	for (ll i = 1; i < n; i++) {
		// If it is the same as last we can use a multiple
		// otherwise we need to find a number that is less
		// but potentially with other prime factors
		// needs to be divisible by a[i] but not a[i-1] or any
		// multiples of its factors
		// find lowest factor in a[i-1] not in a[i]
		// we know the previous gcd
		// we just need to cater for extra factors and stuff
		ll num = a[i-1]/a[i];
		vector<ll> extra;
		for (ll j = 2; j*j <= num; j++) {
			if (!(num % j)) {
				extra.push_back(j);
				while (!(num%j))
					num /= j;
			}
		}
		if (num != 1)
			extra.push_back(num);

		ll current = m/a[i];

		for (ll j = 1; j <= sz(extra); j++) {
			if (j&1)
				current = (current-dfs(extra,j,a[i],m)+MOD)%MOD;
			else
				current =(current+dfs(extra,j,a[i],m)+MOD)%MOD;
		}

		out = (out * current)%MOD;
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

