#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Must be all equal or all unequal, not a mix?
// weird constraint on k
// can't really simulate the operations
// need to also print out the operations
// want to be in a state where the is only one switch from 1 to 0
// all 0 at top with all 1 at bottom takes 3 more steps
// do all pairs of 1 at the top
// this is 2ptr but kinda jank
// edge case where I get all zero at top and all zero at bottom
// now getting wa on pretest 2
// basically some don't need the last bit

void solve() {
	int n;
	cin >> n;
	string ss, tt;
	cin >> ss >> tt;
	vector<int> s, t;
	for (int i = 0; i < n; i++) {
		s.push_back(ss[i]=='1');
		t.push_back(tt[i]=='1');
	}

	int same = 0, opposite = 0, one = 0, zero = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == t[i])
			same = 1;
		else
			opposite = 1;
		if (s[i])
			one++;
		else
			zero++;
	}

	if (same && opposite) {
		cout << "NO\n";
		return;
	}

	int left = 0, right = n-1, current = 1, other = t[0];
	vector<pair<int,int> > ops;
	while (left <= right) {
		while (left < n && s[left] != current)
			left++;
		while (right >= 0 && s[right] != current)
			right--;

		if (right < 0 || left == n || left > right)
			break;
		if (left > 0)
			other ^= 1;
		ops.push_back({left,right});
		current ^= 1;
	}

	// Edge case
	if (!other) {
		cout << "YES\n";
		cout << sz(ops) << "\n";
		for (pair<int,int> i : ops)
			cout << i.f+1 << " " << i.s+1 << "\n";
		return;
	}

	// Should have all top 0 and all bottom 1
	ops.push_back({0,0});
	ops.push_back({0,n-1});
	ops.push_back({1,n-1});

	cout << "YES\n";
	cout << sz(ops) << "\n";
	for (int i = 0; i < sz(ops); i++)
		cout << ops[i].f+1 << " " << ops[i].s+1 << "\n";
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

