#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int x;
	cin >> x; x--;
	vector<int> a(3);
	for (int& i : a) {
		cin >> i;
		i--;
	}

	vector<int> seen(3,0);
	while (x != -1) {
		seen[x] = 1;
		x = a[x];
	}

	cout << (*min_element(all(seen)) ? "YES" : "NO") << "\n";
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

