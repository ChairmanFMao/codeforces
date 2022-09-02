#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	int out = 0;
	vector<int> seen(n,0);
	for (int i = 0; i < n; i++) {
		if ((s[i] == '1' && t[i] == '0') || (s[i] == '0' && t[i] == '1'))
			out += 2;
		if (s[i] == '0' && t[i] == '0') {
			out++;
			seen[i]++;
		}
	}

	for (int i = 0; i < n; i++) {
		if (s[i] == '1' && t[i] == '1') {
			if (i-1 >= 0 && seen[i-1] == 1) {
				seen[i-1]++;
				out++;
			} else if (i+1 < n && seen[i+1] == 1) {
				seen[i+1]++;
				out++;
			}
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

