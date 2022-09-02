#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

bool check(int a, int b, int c) {
	if (a + b <= c)
		return 0;
	if (a + c <= b)
		return 0;
	if (b + c <= a)
		return 0;
	return 1;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	if (!check(a[0],a[1],a[n-1])) {
		cout << "1 2 " << n << "\n";
		return;
	} if (!check(a[0],a[n-2],a[n-1])) {
		cout << "1 " << n-1 << " " << n << "\n";
		return;
	}
	cout << "-1\n";
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

