#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	ll out = 0;
	for (int i : a)
		out += i;

	if (!out) {
		cout << "0\n";
		return;
	}

	sort(all(a),greater<int>());
	if (a[0] > out-a[0]) {
		cout << a[0] - (out - a[0]) << "\n";
	} else {
		cout << "1\n";
	}
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

