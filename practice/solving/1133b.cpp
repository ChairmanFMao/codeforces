#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;
	
	int out = 0;
	map<int,int> remainder;
	for (int i = 0; i < n; i++) {
		if (remainder[(k-a[i]%k)%k]) {
			out += 2;
			remainder[(k-a[i]%k)%k]--;
		} else
			remainder[a[i]%k]++;
	}

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

