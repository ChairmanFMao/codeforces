#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Unsure for the condition for it to be possible
// It wasn't that hard, just matching biggest left to biggest left

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	vector<int> done(n+1,0);
	vector<int> next;
	for (int i : a) {
		if (i <= n && !done[i])
			done[i] = 1;
		else
			next.push_back(i);
	}

	sort(all(next));
	int ptr = sz(next)-1, out = 0;
	for (int i = n; i > 0 && ptr >= 0; i--) {
		if (done[i])
			continue;
		if (next[ptr]%(next[ptr]-i) == i) {
			out++;
			ptr--;
		} else {
			cout << "-1\n";
			return;
		}
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

