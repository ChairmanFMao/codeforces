#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Elements that get to 0 cap
// There are two types of the even cycle
// done by offset of 2 appears in the cycle by 10

// 0 > 0 - cycle -1
// 1 > 2 > 4 > 8 > 6 > 2 - cycle 0
// 2 > 4 > 8 > 6 > 2 - cycle 0
// 3 > 6 > 2 > 4 > 8 > 6 - cycle 1
// 4 > 8 > 6 > 2 > 4 - cycle 0
// 5 > 0 > 0 - cycle -1
// 6 > 2 > 4 > 8 > 6 - cycle 1
// 7 > 4 > 8 > 6 > 2 > 4 - cycle 1
// 8 > 6 > 2 > 4 > 8 - cycle 0
// 9 > 8 > 6 > 2 > 4 > 8 - cycle 1
//
// 1 > 2 > 4 > 8 > 16 > 22 > 24 > 28 > 36 > 42 > 44 > 48 > 56 > 62
// If offset by 10 these sequences can overlap
// 3 > 6 > 12 > 14 > 18 > 26 > 32 > 34 > 38 > 46 > 52 > 54 > 58
// 7 > 14 > 18 > 26 > 32 > etc...
// 9 > 18 > 26 > 32 > etc...

// Expect no found yes on test 239
// 1e16 cap

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	ll first = 1e16+2;
	set<int> out;
	for (int i = 0; i < n; i++) {
		if (a[i] % 10 == 0)
			out.insert(a[i]);
		else if (a[i] % 10 == 5)
			out.insert(a[i]+5);
		else {
			while (a[i] % 10 != 2)
				a[i] += a[i] % 10;
			if ((first - a[i]) % 20) {
				out.insert(1);
			} else {
				out.insert(2);
			}
		}
	}

	cout << (sz(out) == 1 ? "YES" : "NO") << "\n";
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

