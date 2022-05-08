#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

map<string,int> m;

void solve() {
	string s;
	cin >> s;

	cout << m[s] << "\n";
}

void generate() {
	int counter = 1;
	for (int i = 97; i < 97+26; i++) {
		for (int j = 97; j < 97+26; j++) {
			if (j == i)
				continue;
			string s = "";
			s += (char)i;
			s += (char)j;
			m[s] = counter;
			counter++;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout << "\n";
	generate();
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

