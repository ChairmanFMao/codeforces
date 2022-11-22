#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Choose furthest away node for chord?
// maybe even dp of a kind?
// brute force would lead to exponential time complexity
// want to pick the pair with closest value and most to left and
// right of the bounds
// split the number in 2 and move from the midpoint and lowest
// just brute force to find the number of connections
// could be possible to check in O(n^3) I think
// unsure if the greedy allocation is best
// somehow overestimating on the last test case
// if they intersect at the same spot as well
// do multiple lines intersecting at the same point count?
// wa on test 2 now
// not actually that difficult to do, just implementation mainly

void solve() {
	int n, k;
	cin >> n >> k;
	vector<pair<int,int> > a(k);
	vector<int> seen(n+n,0);
	for (pair<int,int>& i : a) {
		cin >> i.f >> i.s; i.f--; i.s--;
		seen[i.f] = 1;
		seen[i.s] = 1;
	}

	vector<int> left;
	for (int i = 0; i < n+n; i++)
		if (!seen[i])
			left.push_back(i);

	for (int i = 0; i < sz(left)/2; i++)
		a.push_back({left[i],left[sz(left)/2+i]});

	ll out = 0;
	// Iterating over the current pair
	for (int i = 0; i < n; i++) {
		// Iterating over the pair we are checking
		for (int j = i+1; j < n; j++) {
			// Actually doing the checking
			int current = 0;
			int big = max(a[j].f,a[j].s), small = min(a[j].f,a[j].s);
			if (a[i].f < big && a[i].f > small)
				current++;
			if (a[i].s < big && a[i].s > small)
				current++;
			if (current == 1)
				out++;
		}
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

