#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Can't get O(n^2) as it will lead to timeout
// map of pairs?

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> a(n-2,vector<int>(3));
	vector<int> seen(n+1, 0);
	// Pairs to their ids
	map<int,vector<int>> m;
	map<int,int> occurs;
	vector<int> out;

	for (int i = 0; i < n-2; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
			occurs[a[i][j]]++;
		}
		sort(all(a[i]));

		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (j == k)
					continue;
				m[a[i][j]].push_back(a[i][k]);
			}
		}
	}

	int start = 0, mid = 0;
	for (int i = 1; i <= n; i++)
		if (occurs[i] == 1)
			start = i;

	out.push_back(start);
	if (occurs[m[start][0]] == 2)
		mid = m[start][0];
	else
		mid = m[start][1];
	out.push_back(mid);

	seen[start] = 1;
	seen[mid] = 1;

	// I think you just need to match an index between start and
	// mid that hasn't been seen yet and it should work until the
	// end
	
	for (int i = 0; i < n-2; i++) {
		int flag = 0;
		for (int j = 0; j < sz(m[start]); j++) {
			for (int k = 0; k < sz(m[mid]); k++) {
				if (!seen[m[start][j]] && m[start][j] == m[mid][k]) {
					int value = m[start][j];
					out.push_back(value);
					seen[value] = 1;
					start = mid;
					mid = value;
					flag = 1;
					break;
				}
			}
			if (flag)
			break;
		}
	}

	for (int i : out)
		cout << i << " ";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

