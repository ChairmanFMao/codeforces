#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	string s, t;
	cin >> s >> t;
	int h1 = stoi(s.substr(0,2)), m1 = stoi(s.substr(3,2)), h2 = stoi(t.substr(0,2)), m2 = stoi(t.substr(3,2));

	int out = 0, sh = h1, sm = m1;
	while (h1 != h2 || m1 != m2) {
		m1++;
		if (m1 >= 60) {
			h1++;
			m1 %= 60;
		} if (h1 >= 24)
			h1 %= 24;
		out++;
	}

	for (int i = 0; i < out/2; i++) {
		sm++;
		if (sm >= 60) {
			sh++;
			sm %= 60;
		} if (sh >= 24)
			sh %= 24;
	}

	cout << (sh < 10 ? "0" : "") << sh << ":" << (sm < 10 ? "0" : "") << sm << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

