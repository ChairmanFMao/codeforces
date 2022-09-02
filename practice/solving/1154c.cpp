#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// One week will lead to
// -3 a, -2 b, -2 c
// min(a/3,min(b/2,c/2))

void solve() {
	ll a, b, c;
	cin >> a >> b >> c;
	ll weeks = min(a/3,min(b/2,c/2));
	a -= weeks * 3;
	b -= weeks * 2;
	c -= weeks * 2;

	vector<int> week = {1,2,3,1,3,2,1};

	ll best = 0;
	for (int i = 0; i < 7; i++) {
		ll ac = a, bc = b, cc = c, d = i, days = 0;
		while (1) {
			if (week[d] == 1) {
				if (ac) {
					ac--;
					days++;
					d++;
				} else
					break;
			} else if (week[d] == 2) {
				if (bc) {
					bc--;
					days++;
					d++;
				} else
					break;
			} else if (week[d] == 3) {
				if (cc) {
					cc--;
					days++;
					d++;
				} else
					break;
			}
			d %= 7;
		}
		
		best = max(days,best);
	}

	cout << weeks*7 + best << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

