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

	sort(all(a),greater<int>());

	ll out = 0;
	map<int,vector<int>> m;
	for (int i : a) {
		if (sz(m[(k-i%k)%k])) {
			out += (i + m[(k-i%k)%k][sz(m[(k-i%k)%k])-1]) / k;
			m[(k-i%k)%k].pop_back();
		} else
			m[i%k].push_back(i);
	}


	vector<int> left;
	for (int i = 0; i < k; i++)
		for (int j : m[i])
			left.push_back(j);

	vector<int> used(sz(left),0);
	int back = sz(left)-1;
	for (int i = 0; i < back; i++) {
		if (left[i]%k + left[back]%k >= k) {
			out += (left[i] + left[back])/k;
			used[i] = 1; used[back] = 1;
			back--;
		}
	}

	// The size of bad should be even here, however it isn't for a case
	vector<int> bad;
	for (int i = 0; i < sz(left); i++)
		if (!used[i])
			bad.push_back(left[i]);
	for (int i = 0; i < sz(bad); i+=2)
		out += (bad[i] + bad[i+1])/k;

	cout << out << "\n";
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

