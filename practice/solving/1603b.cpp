#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// n mod x == y mod n
// both of the numbers are even
// lcm + y if y is smaller than x
// just x if x == y
// (x+y)/2 if y > x
// wa on test 2
// Looked in comments and found a counterexample
// Looked at solution, just maths
// Its a little annoying I didn't make the observation

void solve() {
	ll x, y;
	cin >> x >> y;

	if (x == y) {
		cout << x << "\n";
	} else if (y < x) {
		cout << x + y << "\n";
	} else {
		cout << y - (y % x) / 2 << "\n";
	}
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

