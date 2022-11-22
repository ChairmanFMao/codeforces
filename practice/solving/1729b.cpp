#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (i < n-2 && s[i+2] == '0' && ((i<n-3 && s[i+3] != '0') || (i == n-3))) {
			cout << (char)((s[i]-48)*10 + s[i+1]-48 + 96);
			i += 2;
		} else
			cout << (char)(s[i]-48+96);
	}
	cout << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

