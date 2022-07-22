#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Some sort of clever trick im missing
// Don't get worked up, calm down and try the problem again
// There can be ones with uniques that have q > 3
// I had the right solution however I just didn't implement it right

void solve() {
	string s;
	cin >> s;

	int n = sz(s), open = 0, closed = 0, q = 0;
	for (char c : s) {
		if (c == '(')
			open++;
		if (c == ')')
			closed++;
		if (c == '?')
			q++;
	}

	int qo = n/2 - open, qc = n/2 - closed;

	if (!(qo && qc)) {
		cout << "YES\n";
		return;
	}

	int count = 0;
	vector<int> op, cp;
	for (int i = 0; i < n; i++) {
		if (s[i] == '?' && count < qo) {
			op.push_back(i);
			count++;
		} else if (s[i] == '?' && count >= qo) {
			cp.push_back(i);
			count++;
		}
	}

	swap(op[sz(op)-1],cp[0]);

	set<int> ops(all(op)), cps(all(cp));

	int tot = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(')
			tot++;
		if (s[i] == ')')
			tot--;
		if (s[i] == '?' && ops.count(i))
			tot++;
		if (s[i] == '?' && cps.count(i))
			tot--;
		if (tot < 0) {
			cout << "YES\n";
			return;
		}
	}

	cout << (tot ? "YES" : "NO") << "\n";
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

