#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	string s;
	int n;
	cin >> n >> s;
	if (n < 2) {
		cout << "NO\n";
		return;
	}
	if (n == 2) {
		if (s[0] >= s[1]) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n2\n" << s[0] << " " << s.substr(1) << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

