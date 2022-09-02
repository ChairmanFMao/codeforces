#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Not really possible by brute force simulation
// acc maybe with a map, im not sure
// epicly getting wa on test 2, 58th test case
// expected no, output yes
// unsure what edge cases wouldn't work
// silly error that I didn't notice
// I could've finished it in about 10 mins if I noticed

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	map<int,int> m;
	for (int i = 0; i < n; i++) {
		int shift = (i+a[i])%n;
		if (shift < 0)
			shift += n;
		if (m[shift]) {
			cout << "NO\n";
			return;
		}
		m[shift] = 1;
	}

	cout << "YES\n";
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

