#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n, b;
	cin >> n >> b;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	vector<int> preE(n+1,0), preO(n+1,0);
	for (int i = 1; i <= n; i++) {
		preE[i] = preE[i-1] + (int)(a[i-1] % 2 == 0);
		preO[i] = preO[i-1] + (a[i-1] & 1);
	}
	
	vector<int> out;
	for (int i = 1; i < n; i++) {
		if (preE[i] == preO[i])
			out.push_back(abs(a[i]-a[i-1]));
	}

	sort(all(out));
	int output = 0, cost = 0;
	for (int i = 0; i < sz(out); i++)
		if (cost + out[i] <= b) {
			output++;
			cost += out[i];
		}

	cout << output << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

