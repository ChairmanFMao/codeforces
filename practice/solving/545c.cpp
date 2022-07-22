#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// fell trees can't land on other trees or other fell trees
// I think that you might just be able to do it greedily

void solve() {
	int n;
	cin >> n;
	vector<pair<int,int> > trees(n);
	for (pair<int,int>& i : trees)
		cin >> i.first >> i.second;
	trees.push_back({INT_MAX,0});
	
	int out = 0, last = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (trees[i].first-trees[i].second > last) {
			out++;
			last = trees[i].first;
		} else if (trees[i].first+trees[i].second < trees[i+1].first) {
			out++;
			last = trees[i].first+trees[i].second;
		} else
			last = trees[i].first;
	}

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

