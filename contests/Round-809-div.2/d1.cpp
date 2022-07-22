#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Ideally want the max to be the min
// Currently wa on test 7, overestimating

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	int out = INT_MAX;
	// i is our target number
	for (int i = 1; i <= 3000; i++) {
		int currentMax = -1, currentMin = INT_MAX;
		for (int j = 0; j < n; j++) {
			int closest = a[j]/i;

			if (closest > k)
				closest = k;

			if (closest == 0)
				break;
			currentMax = max(currentMax, a[j]/closest);
			currentMin = min(currentMin, a[j]/closest);
		}
		if (currentMax != -1 && currentMin != INT_MAX)
			out = min(out, currentMax - currentMin);
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

