#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Staying the same doesn't mean decreasing

void solve() {
	int n;
	cin >> n;
	vector<ll> numbers(n);
	ll current = 1;
	for (int i = 0; i < n && current <= 1e12; i++) {
		numbers[i] = current;
		current *= 3;
	}
	
	if (current/3 > 1e9)
		cout << "NO\n";
	else {
		cout << "YES\n";
		for (int i : numbers)
			cout << i << " ";
		cout << "\n";
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

