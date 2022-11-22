#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Just separate the evens and the odds?

void solve() {
	int n;
	cin >> n;

	vector<int> out(n);
	int counter = 1;
	for (int i = (n-1)-!(n&1); i >= 0; i-=2) {
		out[i] = counter;
		counter++;
	}
	for (int i = (n-1) - (n&1); i >= 0; i-=2) {
		out[i] = counter;
		counter++;
	}

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

