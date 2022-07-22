#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Need to think of a way of doing it in less than O(n^2)

void solve() {
	int n;
	cin >> n;
	vector<string> a(n);
	for (string& i : a)
		cin >> i;

	set<string> s;
	for (string i : a)
		s.insert(i);

	for (int i = 0; i < n; i++) {
		int out = 0;
		for (int j = 0; j < sz(a[i]); j++)
			if (s.count(a[i].substr(0,j)) && s.count(a[i].substr(j)))
				out = 1;
		cout << out;
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

