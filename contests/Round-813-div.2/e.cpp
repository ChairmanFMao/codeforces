#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Problem looks very interesting
// Brute force O(n^3) will not work
// Wondering if O(n^2) will pass due to reqs
// Could iterate over some prime stuff ~ 1e4 primes number 1e5
// I think it involves something to do with primes
// prime factors of i,j,k need to multiply to bigger than i,j,k
// Not true when they are all have the same prime
// dp maybe whether taking or leaving all of the primes
// O(n^2) by iterating over i and j then working out k in constant

void solve() {
	int l, r;
	cin >> l >> r;

	
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

