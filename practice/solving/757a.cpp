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
	string b = "Bulbasaur";
	map<char,int> m;
	for (char c : s)
		m[c]++;

	int out = INT_MAX;
	for (char c : b)
		out = min(out, c == 'a' || c == 'u' ? m[c]/2 : m[c]);

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

