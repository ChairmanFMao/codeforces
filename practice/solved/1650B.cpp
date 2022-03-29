#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
	int l, r, a;
	cin >> l >> r >> a;

	int div = r/a;
	int number = (div*a)-1;
	if (number + a <= r)
		number += a;
	if (number < l)
		number = r;
	cout << (number/a) + number%a << "\n";
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

