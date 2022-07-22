#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()


void solve() {
	string s;
	cin >> s;
	int n = sz(s);

	vector<ll> prefix(n+1,0);
	for (int i = 0; i < n; i++) {
		if (s[i] == '1')
			prefix[i+1]++;
		prefix[i+1] += prefix[i];
	}

	ll out = INT_MAX;
	for (int i = 1; i <= n; i++) {
		// This is if there are more ones removed than zeros left
		if (i >= prefix[n])
			out = min(out, prefix[n] - prefix[i] + prefix[i-prefix[n]]);
		// This is if there are more zeros than ones
		else
			out = min(out, prefix[n] - prefix[i]);
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

