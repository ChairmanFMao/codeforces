#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	vector<int> m(5), w(5);
	for (int& i : m)
		cin >> i;
	for (int& i : w)
		cin >> i;
	int hs, hu;
	cin >> hs >> hu;
	
	long double out = 100 * hs - 50 * hu;
	for (int i = 0; i < 5; i++)
		out += max((double)150 * (i+1), (1- (m[i]/(double)250)) * 500 * (i+1) - 50 * w[i]);

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

