#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// we remove all the fixed strings

void solve() {
	string s;
	cin >> s;
	stack<int> pos;
	for (int i = 0; i < sz(s); i++) {
		if (s[i]&1)
			pos.push(i);
		else if (sz(pos))
			pos.pop();
	}

	while (sz(pos)) {
		s[pos.top()] = '0';
		pos.pop();
	}

	cout << s << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

