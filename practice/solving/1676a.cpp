#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	string s;
	cin >> s;
	int one= 0, two = 0;
	for (int i = 0; i<3; i++)
		one += s[i]-48;
	for (int i = 0; i < 3; i++)
		two += s[i+3]-48;
	cout << (one == two ? "YES" : "NO") << "\n";
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

