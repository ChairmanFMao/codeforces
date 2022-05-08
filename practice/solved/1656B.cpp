#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Something is taken away n-1 times, then n-2 until n = 0
// We can actually subtract negatives to add to total
// Just need one number - number = k for good

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	set<int> s;
	for (int i = 0; i < n; i++)
		s.insert(a[i]);
	
	for (int i = 0; i < n; i++) {
		if (s.count(a[i]-k)) {
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
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

