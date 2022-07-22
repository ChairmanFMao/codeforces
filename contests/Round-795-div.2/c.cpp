#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Can't brute force
// Need some way to do the k mathematically

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	int first = -1;
	for (int i = 0; i < n; i++)
		if (s[i] == '1') {
			first = i;
			break;
		}

	int second = -1;
	for (int i = n-1; i >= 0; i--)
		if (s[i] == '1') {
			second = i;
			break;
		}

	ll normal = 0;
	for (int i = 0; i < n-1; i++) {
		normal += (s[i] == '1' ? 10 : 0);
		normal += (s[i+1] == '1' ? 1 : 0);
	}

	// This is if there are zero 1 occurances
	if (second == -1 || first == -1) {
		cout << normal << "\n";
		return;
	}

	// This is if there is only one 1 occurance
	if (second == first) {
		if (second == n-1)
			normal -= 0;
		else if (k >= n-second-1 && second == 0)
			normal -= 9;
		else if (k >= n-second-1)
			normal -= 10;
		else if (k >= first && first != 0)
			normal -= 1;

		cout << normal << "\n";
		return;
	}

	// This is if there are multiple 1 occurances
	if (second != n-1) {
		if (k >= n-second-1) {
			normal -= 10;
			k -= n-second-1;
		}
	}

	if (first != 0) {
		if (k >= first)
			normal -= 1;
	}

	cout << normal << "\n";
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

