#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int s;
	cin >> s;

	int current = 9;
	stack<int> out;
	while (s) {
		if (s < current) {
			out.push(s);
			break;
		}
		s -= current;
		out.push(current);
		current--;
	}

	while (sz(out)) {
		cout << out.top();
		out.pop();
	}
	cout << "\n";
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

