#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// the last element in the list is adjacent to the first
// just erase any that are equal and next to each other
// only 1 of the equal elements is removed
// check to see if you can do one that won't lead to adjacent
// if so, do that operation, otherwise just do the first
// can be done pretty easily in O(n^2)
// getting wa on pretest 3 for some reason
// might need to remove ones initially? - this is not a case
// maybe the location of the removal matters
// remove numbers systematically from most to least occurances?
// greedily remove from the front? - wouldn't work
// I think that if there are 3 or more then there is always a
// way to get the max

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	if (n <= 2) {
		cout << n << "\n";
		return;
	}

	set<ll> s(all(a));
	if (sz(s) >= 3)
		cout << n << "\n";
	else
		cout << 2+(n-2)/2 << "\n";
	
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

