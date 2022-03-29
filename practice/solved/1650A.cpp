#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
	string s;
	char c;
	cin >> s >> c;

	if (!(((int)s.size())&1)) {
		cout << "NO\n";
		return;
	}
	
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == c && !(i&1)) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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

