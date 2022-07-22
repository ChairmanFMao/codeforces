#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// I think that it is just a binary search

bool comp(pair<int,int> a, pair<int,int> b) {
	return a.first == b.first ? a.second < b.second : a.first < b.first;
}

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	vector<pair<int,int> > pairs;
	for (ll i = 0; i < n; i++)
		if (a[i] < i+1)
			pairs.push_back({i+1,a[i]});

	sort(all(pairs),comp);

	ll out = 0;
	for (int i = 0; i < sz(pairs); i++) {
		ll lower = 0, upper = i, mid = 0, prevl = -1, prevu = -1;
		while (1) {
			if (lower == prevl && upper == prevu)
				break;
			mid = (lower+upper)/2;
			prevu = upper; prevl = lower;
			if (pairs[mid].first < pairs[i].second)
				lower = mid;
			else
				upper = mid;
		}
		out += lower + (int)(pairs[0].first < pairs[i].second);
	}

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

