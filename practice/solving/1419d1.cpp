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

	cout << (n-1)/2 << "\n";
	sort(all(a));
	for (int i = 0; i < n/2; i++)
		cout << a[i+n/2] << " " << a[i] << " ";
	if (n&1)
		cout << a[n-1] << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

