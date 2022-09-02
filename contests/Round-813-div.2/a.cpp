#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> p(n);
	for (int& i : p)
		cin >> i;

	int out = 0;
	for (int i = 0; i < k; i++) {
		if (p[i] > k)
			out++;
	}

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

