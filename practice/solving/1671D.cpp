#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	int big = *max_element(all(a)), small = *min_element(all(a));
	int out = 0;
	for (int i = 0; i < n-1; i++)
		out += abs(a[i] - a[i+1]);

	if (big < x) {
		out += x-big;
	}

	if (small > 1) {
		out += small-1;
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

