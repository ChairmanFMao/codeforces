#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Can be decimal
// Binary search wouldn't work I don't think
// dp is not possible here, greedy?
// people can just add the dressing in direction away from pos
// the location must be at a home or at the midpoint of two homes
// I think there is an O(n log n) with sort approach
// store the max before and the max after
// wa on pretest 3 now with binary search approach
// gets drawn into local minima
// binary search the time!
// still get wa on pretest 3
// seeing the furthest left and right all the people can go
// This problem is annoying because it wasn't printing the numbers
// properly and it took me ages to figure out

void solve() {
	ll n;
	cin >> n;
	vector<pair<ll,ll>> a(n);
	for (pair<ll,ll>& i : a)
		cin >> i.f;
	for (pair<ll,ll>& i : a)
		cin >> i.s;

	ll high = 0;
	for (pair<ll,ll>& i : a)
		high = max(high,i.s);

	long double lower = high, upper = 1e9, mid = 0, out = 0;
	// Gets the shortest amount of time to get all people to place
	while (1) {
		if (abs(upper-lower) < 1e-8)
			break;
		mid = (lower+upper)/(long double)2;
		long double left = INT_MIN, right = INT_MAX;
		for (int i = 0; i < n; i++) {
			left = max(left,a[i].f-(mid-a[i].s));
			right = min(right,a[i].f+(mid-a[i].s));
		}

		if (left <= right) {
			out = (left+right)/2;
			upper = mid;
		} else
			lower = mid;
	}

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

