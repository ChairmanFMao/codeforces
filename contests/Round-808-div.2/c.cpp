#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// If how many after can be done doesn't change then do it
// What if we do it backwards where she starts at 0 and needs to get to q

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	stack<char> output;
	int current = 0;
	for (int i = n-1; ~i; i--) {
		if (a[i] <= current)
			output.push('1');
		else if (a[i] > current && current < q) {
			output.push('1');
			current++;
		} else
			output.push('0');
	}

	while (sz(output)) {
		cout << output.top();
		output.pop();
	}
	cout << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

