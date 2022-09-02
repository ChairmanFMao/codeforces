#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// O(n m) will timeout, need something faster
// n+1 - dif in pos for repeats
// the ends seem to be a bit weird
// maybe a segment tree of a kind idk
// each query should be O(log n) or better
// I think working from right to left maybe easier?
// with a change this would lead to n updates potentially
// using a range update structure is would take n to get the answer
// leading to O(n m) - I could try it anyway ig
// wouldn't work anyway with proof
// binary search? somehow? idk
// currently approach is O(n^2 q) however it does works
// reduced it to O(n q), yet its still too slow

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	vector<ll> d(n);
	d[0] = 1;
	ll out = 1, total = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i-1])
			d[i] = d[i-1];
		else
			d[i] = d[i-1]+1;
		out += d[i]*i - total + i+1;
		total += d[i];
	}

	// Queries are just updates to the array
	for (int q = 0; q < m; q++) {
		int b, c; cin >> b >> c; b--;

		if (b && a[b] == a[b-1] && c != a[b])
			out -= 2 * n - b;
		else if (b < n-1 && a[b] == a[b+1] && c != a[b+1])
			out -= 2 * n - b;
		else if (b && a[b] != a[b-1] && c == a[b-1])
			out += 2 * n - b;
		else if (b < n-1 && a[b] != a[b+1] && c == a[b+1])
			out += 2 * n - b;

		a[b] = c;
		cout << out << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

