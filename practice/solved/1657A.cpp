#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
	int x, y;
	cin >> x >> y;

	if (!x && !y) {
		cout << "0\n";
		return;
	}
	
	if (sqrt(x*x+y*y) == (int)sqrt(x*x+y*y)) {
		cout << "1\n";
		return;
	}
	cout << "2\n";
	return;
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

