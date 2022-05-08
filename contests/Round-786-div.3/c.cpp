#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// WA on test 4

void solve() {
	string s, t;
	cin >> s >> t;

	bool a = 0;
	for (char c : t)
		if (c == 'a')
			a = 1;

	ll aCount = 0;
	for (char c : s)
		if (c == 'a')
			aCount++;
	// We need to check if s also has an a
	if (a && sz(t) > 1 && aCount) {
		cout << "-1\n";
		return;
	}

	if (a && sz(t) == 1) {
		cout << "1\n";
		return;
	}

	// We have our intial combination
	ll out = 1ll << aCount;

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

