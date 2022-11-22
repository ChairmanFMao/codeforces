#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Want to take away segments that contribute to the most bad
// points greedily
// wa on test 14, greedy not necessarily best
// even with weighted numbers it doesn't always work

vector<int> points(201,0);
int n, k;

bool bad() {
	for (int i : points)
		if (i > k)
			return 1;
	return 0;
}

void solve() {
	cin >> n >> k;
	vector<pair<int,int> > segments(n);
	vector<int> seen(n,0);
	for (int i = 0; i < n; i++) {
		cin >> segments[i].f >> segments[i].s;
		for (int j = segments[i].f; j <= segments[i].s; j++)
			points[j]++;
	}
	
	vector<int> out;
	while (bad()) {
		int best = 0, index = 0;
		for (int i = 0; i < n; i++) {
			if (seen[i])
				continue;

			int current = 0;
			for (int j = segments[i].f; j <= segments[i].s; j++)
				if (points[j] > k)
					// Works with the weight on each one squared
					current += (points[j] - k)*(points[j]-k);

			if (current > best) {
				best = current;
				index = i;
			}
		}

		for (int i = segments[index].f; i <= segments[index].s; i++)
			points[i]--;
		out.emplace_back(index+1);
		seen[index] = 1;
	}

	cout << sz(out) << "\n";
	for (int i : out)
		cout << i << " ";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

