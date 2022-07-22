#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int& i : a) {
		cin >> i; i--;
	}

	string out = "";
	for (int i = 0; i < m; i++)
		out += "B";

	for (int i = 0; i < n; i++) {
		if (a[i] <= m-1-a[i] && out[a[i]] == 'B')
			out[a[i]] = 'A';
		else if (a[i] <= m-1-a[i] && out[a[i]] == 'A')
			out[m-1-a[i]] = 'A';
		else if (m-1-a[i] < a[i] && out[m-1-a[i]] == 'B')
			out[m-1-a[i]] = 'A';
		else if (a[i] > m-1-a[i] && out[m-1-a[i]] == 'A')
			out[a[i]] = 'A';
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

