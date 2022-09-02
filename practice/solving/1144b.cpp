#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	int total = 0;
	for (int i : a)
		total += i;

	queue<int> f[2], s[2];
	sort(all(a),greater<int>());
	for (int i : a) {
		if (i&1) {
			f[1].push(i);
			s[1].push(i);
		} else {
			f[0].push(i);
			s[0].push(i);
		}
	}

	int current = total, c = 0, out = INT_MAX;
	while (sz(f[c])) {
		current -= f[c].front();
		f[c].pop();
		c ^= 1;
	}

	out = min(current,out);

	current = total;
	c = 1;
	while (sz(s[c])) {
		current -= s[c].front();
		s[c].pop();
		c ^= 1;
	}

	cout << min(current,out) << "\n";

}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

