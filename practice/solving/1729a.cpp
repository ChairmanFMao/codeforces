#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	int d = c > b ? c + c-b : b;
	if (a < d) {
		cout << "1\n";
	} else if (d < a) {
		cout << "2\n";
	} else {
		cout << "3\n";
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

