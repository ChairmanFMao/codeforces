#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
	int a, b;
	cin >> a >> b;
	if (!a) {
		cout << 1 << "\n";
		return;
	}
	cout << a + b + b +1 << "\n";
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

