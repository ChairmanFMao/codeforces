#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Friends not pursuaded could take either
// Attempting to find the minumum number possible pursuading k friends
// Best to convince the first k people

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	k = min(m-1,k);
	int best = 0;
	// This is how many are removed from the start
	for (int i = 0; i <= k; i++) {
		int end = n-(k-i), random = m-k-1, current = INT_MAX;
		// This is how many random are taken from the start
		for (int j = 0; j <= random; j++) {
			current = min(current, max(a[i+j], a[end-1-(random-j)]));
		}
		
		best = max(best,current);
	}

	cout << best << "\n";
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

