#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// This is very simple for O(n^2) but, it won't be good enough
// Two consecutive positive numbers screw it up
// There are also other cases where this is violated though
// O(n^2) gets tle, can think of a O((n/2)^2) method

void solve() {
	ll n = 2e5;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;
	
	ll window[n+1];
	window[0] = 0;
	for (int i = 0; i < n; i++)
		window[i+1] = window[i] + a[i];

	vector<int> positive;
	for (int i = 0; i < n; i++)
		if (a[i] > 0)
			positive.push_back(i);

	for (int i = 0; i < sz(positive)-1; i++) {
		if (positive[i] + 1 == positive[i+1]) {
			cout << "NO\n";
			return;
		}
	}

	for (int i = 0; i < sz(positive); i++) {
		for (int j = i-1; j >= 0; j--) {
			if (a[positive[j]] > a[positive[i]])
				break;
			if (window[positive[i]] - window[positive[j]] > 0) {
				cout << "NO\n";
				return;
			}
		}

		for (int j = i+1; j < sz(positive); j++) {
			if (a[positive[j]] > a[positive[i]])
				break;
			if (window[positive[j]+1] - window[positive[i]+1] > 0) {
				cout << "NO\n";
				return;
			}
		}
	}

	cout << "YES\n";
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

