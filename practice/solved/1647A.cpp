#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
	int n;
	cin >> n;
	
	string out = "";
	int c = 1;
	while (n > 0) {
		if (c) {
			out += "2";
			n -= 2;
		} else {
			out += "1";
			n--;
		}
		c ^= 1;
	}

	if (n == 0)
		cout << out << "\n";
	else
		cout << "1" << out.substr(0,out.size()-1) << "\n";
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

