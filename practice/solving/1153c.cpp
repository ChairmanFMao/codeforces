#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Just need to ensure that we create a regular bracket sequence
// just need to have a () that goes around the whole thing
// need to figure out how many open and closed we need

void solve() {
	int n;
	string s;
	cin >> n >> s;

	if (n&1) {
		cout << ":(\n";
		return;
	}

	int q = 0;
	for (char c : s)
		if (c == '?')
			q++;
	int open = 0, close = 0;
	for (char c : s)
		if (c == '(')
			open++;
		else if (c == ')')
			close++;

	if (open > n/2 || close > n/2) {
		cout << ":(\n";
		return;
	}

	open = n/2 - open;
	close = n/2 - close;

	vector<char> out;

	int val = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			out.push_back('(');
			val++;
		} else if (s[i] == ')') {
			out.push_back(')');
			val--;
		} else if (s[i] == '?') {
			if (open) {
				out.push_back('(');
				val++;
				open--;
			} else {
				val--;
				out.push_back(')');
			}
		}
		if (i != n-1 && val < 1) {
			cout << ":(\n";
			return;
		}
	}

	for (char c : out)
		cout << c;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

