#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Something to do with combinatorics maybe?
// or just greedy perhaps
// just need the ending one to be violated
// wa on pretest 2
// forgot about the lexiographically minimal bit
// need to see if n can be swapped to later in the permutation
// check every factor of x that appears later in the permutation
// I think that brute force should tend to O(n log n)
// still get wa on pretest 2
// will wa on pretest 2 even when I thought I fixed it

void solve() {
	ll n, x;
	cin >> n >> x;
	
	vector<ll> p(n);
	for (ll i = 0; i < n; i++)
		p[i] = i+1;

	p[0] = x;
	p[x-1] = n;
	p[n-1] = 1;

	// This checks if the move is possible
	if (p[x-1] % x && x != n) {
		cout << "-1\n";
		return;
	}

	// This makes the permutation lexicographically smallest
	// We first factorise the number
	// then we are going to iterate over the factors
	ll pos = x-1;
	for (ll i = 2; i < n; i++) {
		if (!(n%i) && !(i%(pos+1)) && i-1 > pos && i != x) {
			swap(p[pos],p[i-1]);
			pos = i-1;
		}
	}

	for (ll i : p)
		cout << i << " ";
	cout << "\n";
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

