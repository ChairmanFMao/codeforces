#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

const int mxN = 2e5;
ll dp[mxN+1];

void solve() {
	memset(dp, 0, sizeof dp);
	int n, k;
	string s;
	cin >> n >> k >> s;
	set<char> c;
	for (int i = 0; i < k; i++) {
		char a;
		cin >> a;
		c.insert(a);
	}

	for (int i = 0; i < n; i++) {
		if (c.count(s[i]))
			dp[i+1] = dp[i]+1;
	}

	ll out = 0;
	for (ll i : dp)
		out += i;
	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

