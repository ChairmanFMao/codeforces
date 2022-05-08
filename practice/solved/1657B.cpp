#include <bits/stdc++.h>
using namespace std;
#define ll long long

// a0 = 0

void solve() {
	int n, b, x, y;
	cin >> n >> b >> x >> y;
	
	ll total = 0, current = 0;
	for (int i = 0; i < n; i++) {
		if (current + x <= b)
			current += x;
		else
			current -= y;
		total += current;
	}
	
	cout << total << "\n";
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

