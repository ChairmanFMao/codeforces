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
	string s;
	cin >> s;
	vector<int> a(5,0);
	for (char c : s) {
		if (c == 'T')
			a[0]++;
		else if (c == 'i')
			a[1]++;
		else if (c == 'm')
			a[2]++;
		else if (c == 'u')
			a[3]++;
		else if (c == 'r')
			a[4]++;
	}

	cout << (*min_element(all(a)) == 1 && n == 5 ? "YES" : "NO") << "\n";
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

