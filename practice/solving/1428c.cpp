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

	stack<char> st;
	for (char c : s) {
		if (sz(st) && st.top() == 'A' && c == 'B')
			st.pop();
		else
			st.push(c);
	}

	int out = 0;
	if (sz(st)) {
		while (sz(st)>1) {
			char last = st.top();
			st.pop();
			char current = st.top();
			if (last == 'B' && current == 'B') {
				st.pop();
			} else
				out++;
		}
		out += sz(st);
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

