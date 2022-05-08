#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Did kinda see the binary search tag and saw how to apply it
// To solve the edge case just check the highest and the highest+1

ll solve2(ll one, ll two) {
	// Binary search the number of days
	ll low = 0, high = 1e16, mid = 0;
	bool flag = 0;
	while (1) {
		if (flag)
			break;
		if (low == high-1)
			flag = 1;
		
		mid = (low+high)>>1;
		if ((mid/2 + (mid&1)) >= one) {
			if (((mid/2 + (mid&1)) - one)/2 + mid/2 >= two)
				high = mid;
			else
				low = mid;
		} else
			low = mid;
	}
	
	return high;
}

void solve() {
	int n;
	cin >> n;
	vector<int> h(n);
	for (int& i : h)
		cin >> i;

	// We set the highest tree height as the one to match
	sort(all(h),greater<int>());
	ll one = 0, one2 = 0, two = 0, two2 = 0, target = h[0];
	for (int i = 0; i < n; i++) {
		two += (target-h[i])/2;
		two2 += (target-h[i]+1)/2;
		one += (target-h[i])&1;
		one2 += (target-h[i]+1)&1;
	}
	
	
	cout << min(solve2(one,two),solve2(one2,two2)) << "\n";
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

