#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Each shelf must have k books

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;

	map<char,int> m;
	for (char c : s)
		m[c]++;

	for (int i = 0; i < k; i++) {
		set<char> current;
		int count = 0;
		for (int j = 0+97; count < n/k && j < 25+97; j++) {
			if (m[(char)j]) {
				current.insert((char)j);
				m[(char)j]--;
				count++;
			}
		}
		for (int j = 0+97; j < 26+97; j++)
			if (!current.count((char)j)) {
				cout << (char)j;
				break;
			}
	}
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

