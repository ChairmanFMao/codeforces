#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// We could make a bitwise array to store how many operations required

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	vector<int> req(31);
	for (int i = 0; i < sz(req); i++)
		for (int j = 0; j < n; j++)
			if (!(a[j] & (1<<i)))
				req[i]++;

	int out = 0;
	for (int i = 30; ~i; i--) {
		if (k >= req[i]) {
			k -= req[i];
			out += 1<<i;
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

