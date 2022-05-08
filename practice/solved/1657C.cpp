#include <bits/stdc++.h>
using namespace std;
#define ll long long

// looked at tutorial, need to consider smaller areas

void solve() {
	int n;
	string s;
	cin >> n >> s;
	int ptr = 0, out = 0, last = 0;
	while (ptr < n) {
		if (s[ptr] == '(' && ptr != n-1) {
			ptr += 2;
			out++;
			last = ptr;
		} else {
			ptr++;
			while (ptr < n && s[ptr] == '(')
				ptr++;
			if (ptr == n)
				break;
			ptr++;
			last = ptr;
			out++;
		}
	}

	cout << out << " " << n-last << "\n";
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

