#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// (r-l+1)/2 ceiling for operations
// convert all of the numbers to zero
// O(n^2) would work due to the contraints
// max cost of n as you could do each of the numbers individually
// just looked at tags, brute force, dp and greedy, I think I'm missing an observation
// Looked at hints, segments of greater length than 2 are not needed
// This is because 2 is optimum due to the ceiling operation
// ended up looking at the tutorial

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	for (int i = 1; i < n; i++)
		a[i] ^= a[i-1];

	set<int> s;
	s.insert(0);
	int out = n;
	for (int i = 0; i < n; i++) {
		// This means two of them xor to zero
		if (s.count(a[i])) {
			out--;
			s.clear();
		}
		s.insert(a[i]);
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

