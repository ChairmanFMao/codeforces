#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// I think a binary search is in order

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (int& i : a)
		cin >> i;

	map<int,int> tasks;
	for (int i : a)
		tasks[i]++;

	int lower = 0, upper = 1e9, mid = 0, prevL = 0, prevU = 0;
	while (1) {
		if (lower == prevL && upper == prevU)
			break;

		mid = (lower+upper)>>1;
		ll extraWork = 0, extraTask = 0;
		for (int i = 1; i <= n; i++) {
			int current = tasks[i];
			if (current > mid)
				extraTask += current - mid;
			else
				extraWork += (mid-current)>>1;
		}
		
		prevL = lower; prevU = upper;
		if (extraWork >= extraTask)
			upper = mid;
		else
			lower = mid;
	}

	cout << upper << "\n";
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

