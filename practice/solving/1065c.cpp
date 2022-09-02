#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// cost is number removed from all towers
// attempting to make all towers the same height
// can only do good slices
// I think it might be a binary search one
// binary search from the top down for each slice
// I think its possible with dp from top down
// just keep testing how if its possible
// acc I think a binary search may work
// getting wa on test 9 with an off by 1 ;-;
// got it in the end but with a lot of wrong submissions
const int mxN = 2e5+1;

void solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	set<ll> s(all(a));
	if (sz(s) == 1) {
		cout << "0\n";
		return;
	}
	
	vector<ll> h(mxN+1,0);
	for (ll i : a)
		h[i]++;
	for (ll i = mxN-1; ~i; i--)
		h[i] += h[i+1];
	for (ll i = mxN-1; ~i; i--)
		h[i] += h[i+1];

	ll start = mxN, small = *min_element(all(a)), moves = 0;
	while (start > small+1) {
		ll left = 0, right = start, mid = 0;
		while (left < right) {
			mid = (left+right)/2;
			if (h[mid]-h[start] <= k)
				right = mid;
			else
				left = mid+1;
		}
		start = right;
		moves++;
	}

	cout << moves << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

