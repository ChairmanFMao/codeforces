#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// print out for every value of k from 1 to n

void solve() {
	int n;
	string s;
	cin >> n >> s;
	vector<int> better;
	ll score = 0;
	for (int i = 0; i < n; i++) {
		int current = s[i] == 'L' ? i : n-i-1;
		score += current;
		int opposite = s[i] == 'L' ? n-i-1 : i;
		if (opposite > current)
			better.push_back(opposite-current);
	}
	
	sort(all(better));
	reverse(all(better));
	int ptr = 0;
	for (int i = 0; i < n; i++) {
		if (ptr < sz(better)) {
			score += better[ptr];
			ptr++;
		}
		cout << score << " \n"[i==n-1];
	}
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

