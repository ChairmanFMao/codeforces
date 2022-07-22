#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	int best = INT_MAX, odd = 0, even = 0;
	for (int i : a) {
		if (i & 1)
			odd = 1;
		else {
			int tmp = i, counter = 0;
			while (!(tmp&1)) {
				tmp >>= 1;
				counter++;
			}
			best = min(best,counter);
			even++;
		}
	}

	if (odd) {
		cout << even << "\n";
	} else {
		cout << even + best-1 << "\n";
	}
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

