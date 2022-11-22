#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// There is a minimum that we can change it by
// can only be set to a number in the range l to r
// max number will always be up 3
// can just go to one end then travel from there
// just some annoying edge cases I think
// wa on test 2 lol
// Just had a l and r the wrong way around lol

void solve() {
	ll l, r, x, a, b;
	cin >> l >> r >> x >> a >> b;

	if (a == b) {
		cout << "0\n";
		return;
	}

	if ((abs(b-l) < x && abs(b-r) < x) || (abs(a-l) < x && abs(a-r) < x) || b < l || b > r) {
		cout << "-1\n";
		return;
	}

	int out = 4;
	if (abs(a-b) >= x)
		out = min(out,1);

	// Then must move to other end
	ll as = a;
	if (abs(a-l) >= x) {
		a = l;
		if (abs(a-b) < x)
			out = min(out,3);
		else
			out = min(out,2);
	}
	a = as;
	if (abs(a-r) >= x) {
		a = r;
		if (abs(a-b) < x)
			out = min(out,3);
		else
			out = min(out,2);
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

