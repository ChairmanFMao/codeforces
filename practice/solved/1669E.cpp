#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// We only want it to differ in one position
// nice little dp solution
int dp[121];

void solve() {
	memset(dp, 0, sizeof dp);
	int n;
	cin >> n;
	vector<string> a(n);
	for (string& s : a)
		cin >> s;

	ll out = 0;
	for (int i = n-1; ~i; i--) {
		dp[(a[i][0]-97)*11 + (a[i][1]-97)]++;
		for (int j = 0; j < 11; j++) {
			if (j != a[i][0]-97)
				out += dp[11*j + a[i][1]-97];
			if (j != a[i][1]-97)
				out += dp[(a[i][0]-97)*11 + j];
		}
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

