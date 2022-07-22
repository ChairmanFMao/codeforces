#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n;
	cin >> n;
	vector<int> p(n);
	for (int& i : p)
		cin >> i;
	int m;
	cin >> m;
	vector<int> q(m);
	for (int& i : q)
		cin >> i;

	vector<int> offset(2,0);
	for (int i : p)
		offset[i&1]++;
	ll out = 0;
	for (int i : q)
		out += offset[i&1];

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

