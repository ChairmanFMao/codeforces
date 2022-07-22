#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Did look at _SSRS solution however, I had a similar idea

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	// Current keeps track of the lowest number
	// out keeps track of the final score
	ll out = 0, current = a[0];
	for (int i = 0; i < n-1; i++) {
		// This is if the next number is greater than the current
		if (a[i] < a[i+1])
			out += a[i+1]-a[i];
		// This is if the number is less than the next one
		else {
			out += a[i]-a[i+1];
			// We also alter current by this amount
			current -= a[i]-a[i+1];
		}
	}
	// We then add the abs of current to get everything to zero
	out += abs(current);

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

