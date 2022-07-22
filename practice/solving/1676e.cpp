#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// This is literally just greedy

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n), x(q);
	for (int& i : a)
		cin >> i;
	for (int& i : x)
		cin >> i;
	
	sort(all(a),greater<int>());
	vector<int> totals(n);
	int total = 0;
	for (int i = 0; i < n; i++) {
		total += a[i];
		totals[i] = total;
	}

	for (int i = 0; i < q; i++) {
		int low = 0, high = n-1, mid = 0, flag = 1;
		while (flag) {
			if (low >= high-1)
				flag = 0;
			mid = (low+high)/2;
			if (totals[mid] >= x[i])
				high = mid;
			else
				low = mid;
		}
		cout << (totals[high] >= x[i] ? high+1 : -1) << "\n";
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

