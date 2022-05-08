#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	string s;
	cin >> s;
	
	if (sz(s) == 1) {
		cout << "Bob " << s[0]-96 << "\n";
		return;
	}

	int total = 0;
	for (char c : s)
		total += c-96;

	if (sz(s) % 2 == 0) {
		cout << "Alice " << total << "\n";
	} else {
		cout << "Alice " << abs(abs(total-min(s[0]-96,s[sz(s)-1]-96)) - min(s[0]-96, s[sz(s)-1]-96)) << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

