#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Sum of all segments are equal
// want the minimum thickness for this case

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	ll total = 0;
	for (int i : a)
		total += i;

	ll out = INT_MAX;
	for (int i = n; i >= 1; i--) {
		if (total%i)
			continue;
		ll current = total/i;
		ll longest = 0, length = 0, subtot = 0, good = 1;
		for (int j = 0; j < n; j++) {
			if (subtot + a[j] > current) {
				good = 0;
				break;
			} else if (subtot + a[j] < current) {
				subtot += a[j];
				length++;
			} else if (subtot + a[j] == current) {
				length++;
				longest = max(longest,length);
				length = 0;
				subtot = 0;
			}
		}
		longest = max(longest,length);

		if (good)
			out = min(longest,out);
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

