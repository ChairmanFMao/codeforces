#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	string s;
	cin >> s;
	map<char,int> occurs;
	set<char> seen;
	for (char c : s) {
		occurs[c]++;
		seen.insert(c);
	}

	int pairs = 0, singles = 0;
	vector<char> u(all(seen));
	for (char c : u) {
		if (occurs[c] > 1)
			pairs++;
		else
			singles++;
	}

	cout << pairs + (singles/2) << "\n";
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

