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

	int f = 0;
	while (f < n && a[f])
		f++;
	if (f < n && !a[f])
		f--;

	int b = n-1;
	while (b >= 0 && a[b])
		b--;
	if (b >= 0 && !a[b])
		b++;

	cout << (f >= b ? 0 : b-f) << "\n";
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

