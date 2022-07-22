#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Tags include greedy?
// Can remove a zero before a one
// Can remove a one before a zero
// Every digit has to touch the other type
// Looked at editorial :skull:
// I get how this works now

void solve() {
	ll n;
	string s;
	cin >> n >> s;

	ll out = n;
	for (int i = 1; i < n; i++)
		if (s[i] != s[i-1])
			out += i;
	
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

