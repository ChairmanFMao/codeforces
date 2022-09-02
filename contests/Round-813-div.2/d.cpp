#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Every node is connected to every other node
// maximum diameter after k operations
// You can change k values within a
// All changed values should go to 1e9
// Is it better to build the graph first?
// Can use segtree for the minimums
// Fastest way from a to b is min(a->b, twice minimum value)
// a -> min -> b leads to twice minimum value
// n ways to get from a to b
// I think, greedily go for the smallest values in a
// all the same, minimum value, otherwise twice min value
// min(second smallest, twice smallest)
// wa on pretest 2, ig my thing doesn't exactly hold
// still wa on pretest 2 with a different approach ;-;
// I think I need to ensure that two 1e9 are next to each other
// Need to stop spamming wa
// Need to test it with next smallest and pair
// Need to think of an edge case
// This thing will be between a node and its neighbor

bool comp(pair<ll,ll> a, pair<ll,ll> b) {
	return a.f < b.f;
}

const int mxN = 1e5;
vector<ll> a(mxN);
ll n, k;

ll process() {
	// Finds the max path between all the points
	ll smallest = LONG_LONG_MAX;
	for (ll i = 0; i < n; i++)
		if (a[i] * 2 < smallest)
			smallest = a[i]*2;

	// checks if there is a pair that exceeds smallest
	// otherwise return the greatest edge below smallest
	ll flag = 0, out = 0;
	for (ll i = 0; i < n-1; i++) {
		if (min(a[i],a[i+1]) >= smallest)
			flag = 1;
		else
			out = max(out,min(a[i],a[i+1]));
	}
	
	return flag ? smallest : out;
}

void solve() {
	cin >> n >> k;
	for (ll i = 0; i < n; i++)
		cin >> a[i];

	// Greedily sets all of the smallest edges with queries
	vector<pair<ll,ll> > p(n);
	for (ll i = 0; i < n; i++)
		p[i] = {a[i],i};
	sort(all(p),comp);
	// Processes using next smallest
	ll original = a[p[k-1].s];
	for (ll i = 0; i < k; i++)
		a[p[i].s] = 1e9;

	// Processes using a pair, next to greatest
	// Just needed to put it next to greatest to win
	ll out = process();
	a[p[k-1].s] = original;
	ll index = 0, value = 0;
	for (ll i = 0; i < n; i++)
		if (a[i] > value) {
			value = a[i];
			index = i;
		}

	if (index)
		a[index-1] = 1e9;
	else
		a[index+1] = 1e9;

	out = max(out,process());
	
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

