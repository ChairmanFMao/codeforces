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

	int tot = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'Q')
			tot++;
		else
			tot--;

		if (tot < 0)
			tot = 0;
	}

	cout << (tot > 0 ? "NO" : "YES") << "\n";
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

