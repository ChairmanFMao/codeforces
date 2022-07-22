#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// x % y = a
// y % z = b
// z % x = c
//
// z = c
// y = c + b
// x = c + b + a

void solve() {
	ll v[3];
	for (ll& i : v)
		cin >> i;

	cout << v[0] + v[1] + v[2] << " " << v[1] + v[2] << " " << v[2] << "\n";
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

