#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// I think that there is something about character frequency
// Whichever character has odd character frequency
// Should've realised it during the contest, :facepalm:

void solve() {
	int n;
	cin >> n;
	map<char,int> m;
	for (int i = 0; i < n+n+1; i++) {
		string s;
		cin >> s;
		for (char c : s)
			m[c]++;
	}

	for (int i = 97; i < 97+26; i++)
		if (m[(char)i] & 1)
			cout << (char)i << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

