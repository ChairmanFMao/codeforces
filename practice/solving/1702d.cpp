#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

bool comp(pair<int,int> a, pair<int,int> b) {
	return a.first > b.first;
}

void solve() {
	string w;
	ll p;
	cin >> w >> p;

	ll total = 0;
	vector<int> used(sz(w),0);
	vector<pair<int,int> > chars;
	for (int i = 0; i < sz(w); i++) {
		chars.push_back({w[i]-96,i});
		total += w[i]-96;
	}

	sort(all(chars), comp);
	int ptr = 0;
	while (total > p && ptr < sz(w)) {
		total -= chars[ptr].first;
		used[chars[ptr].second] = 1;
		ptr++;
	}

	for (int i = 0; i < sz(w); i++)
		if (!used[i])
			cout << w[i];
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

