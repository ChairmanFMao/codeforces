#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// We get a section and we want to maximise the length of the section
// For each x it appears at least k times
// I think there is a binary search of a kind

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	set<int> u;
	map<int,int> occurs;
	for (int i : a) {
		u.insert(i);
		occurs[i]++;
	}
	vector<int> unique(all(u));
	
	int streak = 0, start = 0, last = unique[0]-1, out = 0, lo = 0, so = 0;
	for (int i : unique) {
		if (occurs[i] >= k) {
			if (last+1 != i)
				streak = 0;
			if (!streak)
				start = i;
			streak++;
		}
		else {
			if (streak > out) {
				out = streak;
				so = start;
				lo = start + streak-1;
			}
			streak = 0;
		}
		last = i;
		if (streak > out) {
			out = streak;
			so = start;
			lo = start + streak-1;
		}
	}

	if (streak > out) {
		out = streak;
		so = start;
		lo = start+streak-1;
	}

	if (!out)
		cout << -1 << "\n";
	else
		cout << so << " " << lo << "\n";
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

