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

	vector<int> a(10);
	for (int i = 0; i < 10; i++)
		a[i] = i;

	int out = 0, flag = 1;
	for (int i = 0; i < 11; i++) {
		for (int j = 1; j < 10; j++) {
			if (a[j] <= n)
				out++;
			else {
				flag = 0;
				break;
			}
		}
		if (!flag)
			break;

		for (int i = 0; i < 10; i++)
			a[i] = a[i]*10 + i;
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

