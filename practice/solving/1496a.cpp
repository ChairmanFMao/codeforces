#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;

	// Start
	for (int i = k; i+k <= n; i++) {
		// Length
		for (int j = 1; i+j+k <= n; j++) {
			string b = s.substr(0,i);
			reverse(all(b));
			if (s.substr(0,i) + s.substr(i,j) + b == s) {
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
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

