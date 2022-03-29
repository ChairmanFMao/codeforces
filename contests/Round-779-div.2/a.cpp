#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int out = 0;
	for (int i = 0; i < n; i++) {
		if (i < n-2) {
			if (s.substr(i,3) == "010")
				out++;
		} if (i < n-1) {
			if (s.substr(i,2) == "00")
				out += 2;
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

