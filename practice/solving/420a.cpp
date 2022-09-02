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

	set<char> good = {'A','H','I','M','O','T','U','V','W','X','Y'};
	for (int i = 0; i < sz(s); i++)
		if (!good.count(s[i])) {
			cout << "NO\n";
			return;
		}

	for (int i = 0; i < sz(s)/2; i++) {
		if (s[i] != s[sz(s)-i-1]) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

