#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Potentially dp
// You need to arrange the platforms optimally
// platforms also have to be in order
// determine if its possible to reach the end
// if it is then output the arrangement of the platforms
// greedily place platforms to check if possible then just
// compress them a little?
// platforms cannot intersect with each other
// greedily put them all together until it doesn't cover enough
// wa on test 4
// platform not in a contiguous subsegment?
// I keep getting wa
// can't reach the end with the configuration
// many wa, but finally got there without help!

void solve() {
	int n, m, d;
	cin >> n >> m >> d;
	vector<int> a(m);
	for (int& i : a)
		cin >> i;

	int start = d-1;
	for (int i = 0; i < m; i++)
		start += d-1 + a[i];

	if (start < n) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
	vector<int> gap;
	int plat = n - accumulate(all(a),0);
	while (plat) {
		gap.emplace_back(min(plat,d-1));
		plat -= min(plat,d-1);
	}

	int ptr = 0, count = 0;
	for (int i = 0; i < m; i++) {
		if (ptr < sz(gap)) {
			for (int j = 0; j < gap[ptr]; j++)
				cout << "0 ";
			count += gap[ptr];
			ptr++;
		}

		for (int j = 0; j < a[i]; j++)
			cout << i+1 << " ";
		count += a[i];
	}

	while (count < n) {
		cout << "0 ";
		count++;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

