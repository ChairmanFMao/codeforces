#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	vector<int> a(4);
	for (int& i : a)
		cin >> i;

	int total = 0;
	for (int i : a)
		total += i;

	cout << (total == 4 ? 2 : total ? 1 : 0) << "\n";
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

