#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

ll power(int f, int s) {
	ll out = 1;
	for (int i = 0; i < s && out < 1e9; i++)
		out *= f;
	return out;
}

void solve() {
	int x, y;
	cin >> x >> y;

	int div = y/x;
	if (y % x || !div) {
		cout << "0 0\n";
		return;
	}
	
	for (int i = 1; i < 100; i++) {
		for (int j = 1; j < 10; j++) {
			if (power(i,j) == div) {
				cout << j << " " << i << "\n";
				return;
			}
		}
	}

	cout << "0 0\n";
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

