#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Just do a greedy kinda thing
// somehow forming a cyclic graph
// I think I have a partial solution but not smallest

vector<int> after(26,-1), used(26,0);
int n;
string s;

bool loop(int start, int other) {
	if (after[start] != -1 || start == other)
		return 1;
	int save = start;
	after[start] = other;
	set<int> seen;
	while (start != -1) {
		if (seen.count(start)) {
			after[save] = -1;
			return 1;
		}
		seen.insert(start);
		start = after[start];
	}
	after[save] = -1;
	return 0;
}

void solve() {
	cin >> n >> s;

	for (int i = 0; i < 26; i++) {
		after[i] = -1;
		used[i] = 0;
	}

	set<char> done;
	for (int i = 0; i < n; i++) {
		if (done.count(s[i]))
			continue;
		int current = 0;
		while (used[current] || (sz(done) != 25 && loop(current,s[i]-97))) {
			current = (current+1)%26;
		}

		after[current] = s[i]-97;
		used[current] = 1;
		done.insert(s[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 26; j++)
			if (after[j] == s[i]-97) {
				cout << (char)(j+97);
				break;
			}
	}

	cout << "\n";
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

