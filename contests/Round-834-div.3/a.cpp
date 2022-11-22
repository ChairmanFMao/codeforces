#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	string s;
	cin >> s;
	if (s[0] == 's')
		s = 'e' + s;
	if (s[0] == 'e')
		s = 'Y' + s;

	vector<char> c = {'Y','e','s'};
	int ptr = 0;
	for (ll i = 0; i < sz(s); i++) {
		if (s[i] != c[ptr]) {
			cout << "NO\n";
			return;
		}
		ptr = (ptr+1)%sz(c);
	}
	cout << "YES\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

