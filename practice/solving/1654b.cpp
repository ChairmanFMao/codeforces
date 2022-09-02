#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	string s;
	cin >> s;
	map<char,int> m;
	for (char c : s)
		m[c]++;

	int ptr = 0;
	while (m[s[ptr]] > 1) {
		m[s[ptr]]--;
		ptr++;
	}

	cout << s.substr(ptr) << "\n";
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

