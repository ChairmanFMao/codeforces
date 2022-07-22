#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n = 14;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	ll best = 0, score = 0;
	for (int i = 0; i < n; i++) {
		score = 0;
		int add = a[i]/n, left = a[i]%n, tmp = a[i];
		a[i] = 0;
		for (int j = 0; j < n; j++)
			a[j] += add;
		for (int j = i+1; j <= i+left; j++)
			a[j%n]++;
		
		for (int j : a)
			if (!(j&1))
				score += j;

		best = max(best,score);

		for (int j = 0; j < n; j++)
			a[j] -= add;
		for (int j = i+1; j <= i+left; j++)
			a[j%n]--;
		a[i] = tmp;
	}

	cout << best << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

