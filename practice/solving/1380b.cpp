#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	string s;
	cin >> s;
	vector<int> occurs(3);
	for (int i = 0; i < sz(s); i++)
		occurs[s[i] == 'R' ? 0 : s[i] == 'P' ? 1 : 2]++;

	int index = 0, best = 0;
	for (int i = 0; i < 3; i++)
		if (occurs[i] > best) {
			best = occurs[i];
			index = i;
		}

	char out = "RPS"[(index+1)%3];
	
	for (int i = 0; i < sz(s); i++)
		cout << out;
	cout << "\n";
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

