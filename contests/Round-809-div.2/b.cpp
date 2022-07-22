#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// There needs to be an even difference between the numbers

void solve() {
	int n;
	cin >> n;
	vector<int> c(n);
	for (int& i : c)
		cin >> i;

	map<pair<int,int>, pair<int,int>> m;
	for (int i = 1; i <= n; i++)
		m[{i,1}].f = 1;

	for (int i = 0; i < n; i++) {
		if ((m[{c[i],0}].f - i-1) % 2 == 0) {
			m[{c[i],0}].f = i;
			m[{c[i],0}].s++;
		}
		if ((m[{c[i],1}].f - i-1) % 2 == 0) {
			m[{c[i],1}].f = i;
			m[{c[i],1}].s++;
		}
	}

	for (int i = 1; i <= n; i++)
		cout << max(m[{i,0}].s, m[{i,1}].s) << " ";
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
