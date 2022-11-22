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
	map<char,int> occurs;
	for (char c : s) occurs[c]++;
	for (char c : t) occurs[c]++;
	for (auto i = occurs.begin(); i != occurs.end(); i++)
		if (i->s & 1) {
			cout << "NO\n";
			return;
		}
	map<pair<char,char>, int> m;
	for (int i = 0; i < n; i++)
		m[{min(s[i],t[n-1-i]),max(s[i],t[n-1-i])}]++;

	int odd = 0, even = 0;
	for (auto i = m.begin(); i != m.end(); i++) {
		if (i->s & 1)
			odd++;
		else
			even++;
	}

	cout << ((odd == 1 && (n&1)) || (!odd && !(n&1)) ? "YES" : "NO") << "\n";
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

