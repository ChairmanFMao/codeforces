#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Unsure of an easy way to test if the blue peg is hit
// we can just do it one way and multiply it by n without loss of
// generality
// the array generated will be at most length n-1
// an O(n^2) approach would be efficient enough
// do dp from the end states to build up to the original?
// I think that this might actually work if we group all of the
// states with the same number removed together
// its just generating some of the more obscure ending cases
// need a way to generate the more complex endings
// just check if all of the numbers are within
// the last one to take away has to be somewhere in the other half
// if we choose a left and right point we can find the number of
// ways that that state could be obtained
// this actually turns out quite differently if n is even or odd
// This is a very cool problem

const ll mxN = 5000;
vector<ll> fact(mxN+1,1), inv(mxN+1,1), dp(mxN+1,0);
ll n, p;

ll fastPow(ll base, ll exp) {
	base %= p;
	ll out = 1;
	for (;exp;exp>>=1) {
		if (exp&1)
			out = (out * base)%p;
		base = (base * base)%p;
	}
	return out;
}

void genFact() {
	for (ll i = 1; i <= mxN; i++) {
		fact[i] = (fact[i-1] * i)%p;
		inv[i] = fastPow(fact[i],p-2);
	}
}

ll choose(ll a, ll b) {
	return (fact[a] * ((inv[b] * inv[a-b])%p))%p;
}

void check() {
	cout << "dp: ";
	for (ll i = 0; i <= n; i++)
		cout << dp[i] << " ";
	cout << "\n";
}

void solve() {
	cin >> n >> p;
	genFact();

	if (!(n&1))
		dp[2] += n;

	// We are using the other point as zero
	// we don't need to iterate over it as we can multiply by n
	// to cater for all of the cases
	for (ll i = 1; i < (n+1)/2; i++) {
		ll other = i;
		if (!(n&1))
			other++;
		// This is how many we are choosing
		for (ll j = 0; j <= i-1; j++)
			dp[j+3] = (dp[j+3] + (n * ((other * choose(i-1,j))%p)))%p;
	}

	for (ll i = 0; i < n; i++)
		dp[i+1] = (dp[i+1] + (dp[i] * (n-i)))%p;

	cout << dp[n];
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

