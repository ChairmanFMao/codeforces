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

	if (m == 0) {
		cout << "1\n";
		return;
	}

	vector<int> out(n,1);
	int moves = 0;
	int output = 0;
	for (int i = 0; i < n-1 && moves < m; i+=2) {
		output++;
		out[i] = 0;
		moves++;
	}

	if (n&1 && moves < m)
		moves++;

	for (int i = 1; i < n && moves < m; i+=2) {
		output--;
		out[i] = 0;
		moves++;
	}

	

	cout << output << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

