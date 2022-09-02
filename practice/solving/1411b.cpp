#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	ll n;
	cin >> n;
	string s;
	while (1) {
		bool flag = 1;
		s = to_string(n);
		for (int i = 0; i < sz(s); i++) {
			if (s[i] == 48)
				continue;
			if (n%(s[i]-48)) {
				flag = 0;
				break;
			}
		}
		if (flag)
			break;
		n++;
	}

	cout << n << "\n";
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

