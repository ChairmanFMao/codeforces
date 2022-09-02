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
	vector<int> out(n);
	for (int i = 0; i < n; i++)
		out[i] = i+1;

	for (int i = 0; i < n-1; i+=2)
		swap(out[i],out[i+1]);

	if (n&1)
		swap(out[n-1],out[n-3]);

	for (int i : out)
		cout << i << " ";
	cout << "\n";
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

