#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int a, b;
	cin >> a >> b;
	string out = "";
	for (int i = 0; i < min(a,b); i++)
		out += "10";
	for (int i = 0; i < max(a,b) - min(a,b); i++)
		out += a > b ? "0" : "1";

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

