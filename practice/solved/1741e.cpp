#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Attempting to reverse the operation
// greedy allocation is not a good idea
// just select a group of numbers so that they sum to length?
// but they also have to be not next to each other
// maybe some dp thing?
// would involve both pushing and pulling

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	vector<int> good(n+2,0);
	good[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (i-a[i-1]-1 >= 0 && good[i-a[i-1]-1])
			good[i] = 1;
		if (i+a[i-1]+1 <= n+1 && good[i-1])
			good[i+a[i-1]] = 1;
	}

	cout << (good[n] ? "YES" : "NO") << "\n";
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

