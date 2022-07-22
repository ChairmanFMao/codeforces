#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n;
	cin >> n;
	vector<int> p(n);
	for (int& i : p)
		cin >> i;

	int out = 0, current = -1;
	for (int i = 0; i < n; i++) {
		if (current == -1)
			current = p[i];
		else {
			if (p[i] > current)
				current = p[i];
			else {
				out++;
				current = -1;
			}
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

