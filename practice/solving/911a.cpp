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

	int small = *min_element(all(a));
	vector<int> index;
	for (int i = 0; i < n; i++)
		if (a[i] == small)
			index.push_back(i);

	int out = INT_MAX;
	for (int i = 0; i < sz(index)-1; i++)
		out = min(out,index[i+1]-index[i]);

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

