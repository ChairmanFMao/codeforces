#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	map<char,int> occurs;
	int score = 0;
	for (char c : s) {
		if (!occurs[c])
			score++;
		score++;
		occurs[c]++;
	}

	cout << score << "\n";
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

