#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	string s, t;
	cin >> s >> t;
	map<char,int> m;
	for (char c : s)
		m[c]++;
	for (char c : t)
		m[c]++;

	set<char> seen;
	vector<int> out;
	for (char c : s)
		if (!seen.count(c)) {
			out.push_back(m[c]);
			seen.insert(c);
		}

	for (char c : t)
		if (!seen.count(c)) {
			out.push_back(m[c]);
			seen.insert(c);
		}

	cout << sz(out)-1 << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

