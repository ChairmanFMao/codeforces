#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n, r, b;
	cin >> n >> r >> b;
	int big = max(r,b), small = min(r,b);
	int div = big/(small+1), mod = big%(small+1);
	string out = "";
	for (int i = 0; i < div; i++)
		out += r == big ? "R" : "B";

	for (int i = 0; i < b; i++) {
		out += r==big ? "B" : "R";
		for (int j = 0; j < div +(i < mod ? 1 : 0); j++) {
			out += r == big ? "R" : "B";
		}
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

