#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n;
	cin >> n;

	set<pair<int,int> > end;

	// i is upwards, k is downwards
	for (int i = 0; i <= (n+1)/2; i++) {
		int k = (n+1)/2 - i;
		// j is right, l is left
		for (int j = 0; j <= n/2; j++) {
			int l = n/2 - j;

			if (i + j + k + l == n)
				end.insert({i-k,j-l});
		}
	}

	// i is upwards, k is downwards
	for (int i = 0; i <= n/2; i++) {
		int k = n/2 - i;
		// j is right, l is left
		for (int j = 0; j <= (n+1)/2; j++) {
			int l = (n+1)/2 - j;

			if (i + j + k + l == n)
				end.insert({i-k,j-l});
		}
	}

	cout << sz(end) << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

