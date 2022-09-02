#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Looked at tutorial because it was before contest

void solve() {
	int n, k, d;
	cin >> n >> k >> d;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	int best = INT_MAX, out = 0;
	for (int i = 0; i < n-d; i++) {
		set<int> s;
		for (int j = i; j < i+d; j++)
			s.insert(a[j]);

		if (sz(s) < best) {
			best = sz(s);
			out = i;
		}
	}

	cout << out+1 << "\n";
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

