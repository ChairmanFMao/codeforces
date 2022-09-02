#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// dp maybe?

void solve() {
	int n;
	cin >> n;
	vector<int> x(n);
	vector<int> y(n);
	vector<int> done(n, 0);
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];

	int out = 0;
	if (*max_element(all(x)) > 0)
		out += 2 * (*max_element(all(x)));
	if (*min_element(all(x)) < 0)
		out += 2 * abs(*min_element(all(x)));
	if (*max_element(all(y)) > 0)
		out += 2 * (*max_element(all(y)));
	if (*min_element(all(y)) < 0)
		out += 2 * abs(*min_element(all(y)));

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

