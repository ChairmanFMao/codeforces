#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	string s;
	cin >> s;
	int n = sz(s);
	vector<int> before(n,0), after(n,0);
	for (int i = 1; i < n; i++)
		before[i] = before[i-1] + (s[i-1] == '0');
	for (int i = n-2; ~i; i--)
		after[i] = after[i+1] + (s[i+1] == '1');

	int out = 0;
	for (int i = 0; i < n; i++)
		if (before[i] < 1 && after[i] < 1)
			out++;

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

