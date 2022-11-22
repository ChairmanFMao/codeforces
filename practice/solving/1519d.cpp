#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Just simulate them all with O(n^3) leads to 1e11 worst case
// reverse one contiguous subsegment of a to maximise
// solve recursively?
// unsure how to do the reversals efficiently
// grow out greedily with 2ptr from all locations?
// The brute force solution gets tle when n = 5000
// It takes about 30-60 seconds to run when I do it locally
// looked at editorial, just use dp to make it faster

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n), b(n);
	for (ll& i : a)
		cin >> i;
	for (ll& i : b)
		cin >> i;

	// this just does a prefix calculation
	vector<ll> prefix(n+1,0);
	for (int i = 1; i <= n; i++)
		prefix[i] = prefix[i-1] + a[i-1]*b[i-1];

	ll out = prefix[n];
	// Center
	for (int i = 0; i < n; i++) {
		// length
		// This has the center as i and odd length
		ll current = a[i] * b[i];
		for (int l = i-1, r = i+1; l >= 0 && r < n; l--, r++) {
			current += a[l] * b[r];
			current += a[r] * b[l];
			out = max(out, current + prefix[l] + prefix[n]-prefix[r+1]);
		}

		// This has the center as between i and i+1 and even length
		current = 0;
		for (int l = i, r = i+1; l >= 0 && r < n; l--, r++) {
			current += a[l] * b[r];
			current += a[r] * b[l];
			out = max(out, current + prefix[l] + prefix[n]-prefix[r+1]);
		}
	}

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

