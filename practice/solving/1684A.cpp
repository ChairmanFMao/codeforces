#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n;
	cin >> n;
	string s = to_string(n);
	char smallest = '9';
	for (int i = 0 ; i < sz(s); i++) {
		if (s[i] < smallest)
			smallest = s[i];
	}

	cout << (sz(s) == 2 ? s[1] : smallest) << "\n";
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

