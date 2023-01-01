#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Just not square numbers?
// It might be xor basis but I don't know
// values in a are bounded by n, we need to take advantage of this
// max of 2e5
// store prime factorised representation of numbers with a bitmask
// then we can do xors and we want them to be non-zero
// there are only about 10000 primes under 2e5 ish
// a bitmask won't work due to too many primes factors
// they have to be continuous
// maybe this is just 2ptr
// unsure how to get a faster than O(n^2) algorithm
// just store where the complete subarrays are?
// I think that this is possible with dynamic programming
// my current approach would still lead to O(n^2) tho I think
// just xor it with everything bigger and go upwards
// actually it might be a bit different idk
// just want the number of ways to make non-square numbers
// we can't sort without some original id number
// binary search outwards?
// actually I don't think that this would work
// we could generate a prefix factors vector
// could just try to generate all the squares and take this total
// away from the total number
// using a map would still lead to O(n^2) I think
// just have 2ptr and advance until you find a square?
// then you move the first pointer forward until not a square
// get the prefix of even prime totals and remove this
// I don't feel that it would be prime factorisation
// something binary
// The O(n^2) approach times out
// get the xor for all later ones and then just continuously
// reduce the number
// this would still lead to O(n^2) I think
// I tried a similar thing with a map and it also timed out

const ll mxV = 1<<18, mxN = 2e5;
ll seen[mxV], prefix[mxN+1], a[mxN];

void solve() {
	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++)
		cin >> a[i];

	for (ll i = 0; i < mxV; i++)
		seen[i] = 0;

	prefix[0] = 0;
	for (ll i = 1; i <= n; i++)
		prefix[i] = prefix[i-1] ^ a[i-1];

	ll out = 0;
	for (ll j = 0; j < n; j++) {
		seen[prefix[j]]++;
		for (ll i = 0; i*i < mxV; i++)
			out += seen[(i*i)^prefix[j+1]];
	}

	cout << ((n*(n+1))/2)-out << "\n";
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

