#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	int total = 0;
	for (int i : a)
		total += i;

	if (s > total) {
		cout << "-1\n";
		return;
	}

	vector<int> lCost(n+1,0), rCost(n+1,0);
	int good = 0;
	for (int i = 0; i < n; i++) {
		if (a[i]) {
			good++;
			lCost[good] = i+1;
		}
	}
	good = 0;
	for (int i = n-1; ~i; i--) {
		if (a[i]) {
			good++;
			rCost[good] = n-i;
		}
	}

	s = total - s;
	int out = INT_MAX;
	for (int i = 0; i <= s; i++)
		out = min(out, lCost[i] + rCost[s-i]);

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

