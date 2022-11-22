#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// We want the max of n
// I have gravely misunderstood the question
// I think that this might even make it eaiser tho
// now I just need to think about the prime factorisation
// This is actually a really easy question

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
	ll n, m;
	cin >> n >> m;
	ll ns = n;
	map<ll,ll> primes;
	for (ll i = 2; i*i <= n; i++)
	 	while (!(n%i)) {
			primes[i]++;
			n /= i;
		}

	if (n>1)
		primes[n]++;

	ll two = primes[2], five = primes[5];
	ll best = 1;
	while (two < five) {
		if (best*2 <= m) {
			best *= 2;
			two++;
		} else
			break;
	}

	while (two > five) {
		if (best*5 <= m) {
			best *= 5;
			five++;
		} else
			break;
	}

	while (best*10 <= m)
		best *= 10;

	// we now want to get best as close to m as possible
	best *= m/best;
	ll out = best;

	cout << ns*out << "\n";
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

