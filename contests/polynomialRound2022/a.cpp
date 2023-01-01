#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	ll n;
	string s;
	cin >> n >> s;

	ll one = 0;
	for (char c : s)
		if (c&1)
			one++;

	one = (one+1)/2;
	string out = "";
	for (ll i = 1; i < n; i++) {
		if (s[i]&1 && one > 0) {
			out += "-";
			one--;
		} else
			out += "+";
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

