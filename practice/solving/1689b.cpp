#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// I think O(n^2) will be fine for this problem
// There are issues with greedy taking you to bad place
// Only really matters for last one

void solve() {
	int n;
	cin >> n;
	vector<int> p(n), used(n,0);
	for (int& i : p)
		cin >> i;

	if (n == 1) {
		cout << "-1\n";
		return;
	}

	vector<int> out;
	for (int i = 0; i < n; i++) {
		if (i == n-2) {
			if (!used[n-1]) {
				out.push_back(p[n-1]);
				for (int j = 0; j < n-1; j++)
					if (!used[j]) {
						out.push_back(p[j]);
						break;
					}
				break;
			}
		}

		int best = INT_MAX, bestIndex = -1;
		for (int j = 0; j < n; j++) {
			if (!used[j] && p[j] < best && i != j) {
				best = p[j];
				bestIndex = j;
			}
		}
		out.push_back(best);
		used[bestIndex] = 1;
	}

	for (int i : out)
		cout << i << " ";
	cout << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

