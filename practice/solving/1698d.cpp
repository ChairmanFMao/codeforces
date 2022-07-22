#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// I looked at editorial, very clever binary search logic
// If there is an odd number in the range then the fixed point is in
// that range, otherwise it is in the other half

void solve() {
	int n;
	cin >> n;
	
	int lower = 1, upper = n, mid = 0;
	while (lower < upper) {
		mid = (lower+upper)>>1;

		cout << "? " << lower << " " << mid << endl;
		int count = 0;
		for (int i = 0; i < mid-lower+1; i++) {
			int a;
			cin >> a;
			// This checks if a is in the range
			if (lower <= a && a <= mid)
				count++;
		}
		
		if (count & 1)
			upper = mid;
		else
			lower = mid+1;
	}

	cout << "! " << lower << endl;
}

int main(void) {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

