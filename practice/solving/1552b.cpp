#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// I think it could be sortings problem
// O(n^2) shouldn't work here
// Trying to think of another way to do it but unsure
// O(n^2) gets TLE

void solve() {
	int n;
	cin >> n;
	vector<vector<int> > a(n,vector<int>(5));
	for (vector<int>& i : a)
		for (int& j : i)
			cin >> j;

	int out = 0;
	for (int i = 1; i < n; i++) {
		int count = 0;
		for (int j = 0; j < 5; j++)
			if (a[out][j] > a[i][j])
				count++;
		if (count >= 3)
			out = i;
	}

	int good = 1;
	for (int i = 0; i < n; i++) {
		if (i == out)
			continue;
		int count = 0;
		for (int j = 0; j < 5; j++)
			if (a[out][j] > a[i][j])
				count++;
		if (count >= 3)
			good = 0;
	}

	cout << (good ? out+1 : -1) << "\n";
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

