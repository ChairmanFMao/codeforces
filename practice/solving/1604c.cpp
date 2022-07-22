#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Think about lcm not primes, kinda similar

void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	bool out = 1;
	for (int i = 0; i < n; i++) {
		bool flag = 0;
		// Finds if the number is divisible by the lcm or not
		for (int j = 2; j <= i+2; j++) {
			if (a[i] % j) {
				flag = 1;
				break;
			}
		}
		out &= flag;
	}
	
	// If all the numbers are good then the output is good
	cout << (out ? "YES" : "NO") << "\n";
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

