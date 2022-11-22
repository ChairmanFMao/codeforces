#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Winners score multiplied by k^2, losers by k
// just need to ensure that all factors of the numbers divide by 3
// expect no, found yes
// tle on test 6, just need to pre generate all the primes
// tle on test 8 even with pregenerated primes
// O(n * 3401) is too slow
// It is slow due to when prime numbers are put in
// O(n * 168) is also too slow
// Ended up looking at the tutorial
// It was a binary search in the end ;-;

void solve() {
	ll a, b;
	cin >> a >> b;
	ll c = a*b;
	
	ll lower = 0, upper = 1e6, mid = 0;
	while (lower < upper) {
		mid = (lower+upper)>>1;
		if (mid*mid*mid < c)
			lower = mid+1;
		else
			upper = mid;
	}

	cout << (upper*upper*upper == c && !(a%upper) && !(b%upper) ? "YES" : "NO") << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

