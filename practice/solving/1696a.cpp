#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n, z;
	cin >> n >> z;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	int out = INT_MIN;
	for (int i : a)
		out = max(out, i | z);

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

