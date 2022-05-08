#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// 2^15 cap for the numbers
// Just find the shortest distance to a greater power of 2

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;
	
	for (int i : a) {
		if (!i) {
			cout << "0 ";
			continue;
		}
		int out = 1e9;
		for (int j = 0; j < 32; j++)
			out = min(out,15-__builtin_ctz(i+j)+j);

		cout << out << " ";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout << "\n";
	solve();
}

