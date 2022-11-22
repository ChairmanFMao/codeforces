#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Find the nearest coprime to n for each?
// just try all of the subsets?
// can perform the operation multiple times on the same spot
// any subset of operations with a sum less than n
// dfs this recursively?

const int mxN = 20;
vector<int> a(mxN);
int n;
map<int,int> ops;
int out = INT_MAX;

bool valid() {
	vector<int> b(all(a));
	for (auto i = ops.begin(); i != ops.end(); i++)
		for (int j = 0; j < (i->s); j++)
			b[i->f] = __gcd(b[i->f],i->f+1);

	int g = b[0];
	for (int i = 0; i < n; i++)
		g = __gcd(b[i], g);

	return g == 1;
}

void dfs(int node, int cost) {
	if (valid())
		out = min(out,cost);

	for (int i = node; i < n; i++) {
		if (cost + n-i < out) {
			ops[i]++;
			dfs(i,cost+n-i);
			ops[i]--;
		}
	}
}

void solve() {
	cin >> n;
	out = n;
	ops.clear();
	for (int i = 0; i < n; i++)
		cin >> a[i];

	dfs(0,0);
	
	cout << out << "\n";
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

