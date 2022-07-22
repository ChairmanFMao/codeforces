#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

bool pal(string s) {
	for (int i = 0; i < sz(s)/2; i++)
		if (s[i] != s[sz(s)-1-i])
			return 0;
	return 1;
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	int out = 0;
	int half = sz(s)/2;
	if (pal(s.substr(0,half) + s.substr(half+1))) {
		int left = half, right = half;
		while (left >= 0 && s[left] == s[half])
			left--;
		while (right < n && s[right] == s[half])
			right++;
		out += right-left-1;
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

