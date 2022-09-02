#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Need to be divisible by 6 and 10
// zero at end, digits sum to multiple of 3

void solve() {
	string s;
	cin >> s;

	sort(all(s));
	
	int out = 0, zero = 0, other = 0;
	for (char c : s) {
		if (c%2 == 0 && zero)
			other = 1;
		if (c == '0')
			zero = 1;
		out += c-48;
	}

	cout << (!(out%3) && zero && other ? "red" : "cyan") << "\n";
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

