#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int& i : a)
		cin >> i;
	for (int& i : b)
		cin >> i;

	ll out = 0;
	for (int i = 0; i < n-1; i++) {
		if (abs(a[i] - a[i+1]) + abs(b[i] - b[i+1]) > abs(a[i] - b[i+1]) + abs(b[i] - a[i+1]))
			swap(a[i+1],b[i+1]);
		out += abs(a[i] - a[i+1]) + abs(b[i] - b[i+1]);
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

