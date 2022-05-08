#include <bits/stdc++.h>
using namespace std;
#define ll long long

// This problem was very annoying in the contest - I should've been able to solve it

void solve() {
	string s;
	cin >> s;
	
	// This keeps track of the removals
	int out = 0;
	// This keeps track of open characters
	set<char> open;
	// This iterates through all of the characters
	for (char c : s) {
		// If there was an opening character
		if (open.count(c)) {
			// Remove all of the characters inbetween - minus one for the open
			out += open.size()-1;
			// You can then clear open
			open.clear();
		} else
			// Otherwise add the character to open
			open.insert(c);
	}
	// Output out + the remaining characters in open
	cout << out + open.size() << "\n";
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

