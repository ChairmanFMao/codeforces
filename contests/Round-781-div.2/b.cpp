#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
	int n;
	cin >> n;
	vector<int> numbers(n);
	for (int& i : numbers)
		cin >> i;
	
	set<int> occuring;
	map<int,int> occurs;
	for (int i : numbers) {
		occuring.insert(i);
		occurs[i]++;
	}

	int best = 0;
	vector<int> u(occuring.begin(),occuring.end());
	for (int i : u) {
		if (occurs[i] > best)
			best = occurs[i];
	}

	ll out = 0, score = best;
	while (score < n) {
		out++;
		out += min(n-score, score);
		score += min(n-score, score);
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

