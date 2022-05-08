#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	
	vector<int> bits(n);
	for (int i = 0; i < n; i++)
		bits[i] = s[i] & 1;
	vector<int> uses(n);
	if (k & 1) {
		k--;
		int flip = -1;
		for (int i = 0; i < n; i++)
			if (bits[i]) {
				flip = i;
				break;
			}
		
		if (flip == -1)
			flip = n-1;

		uses[flip]++;

		for (int i = 0; i < n; i++) {
			if (i == flip)
				continue;
			bits[i] ^= 1;
		}
	}
	
	int ptr = 0, sptr = 0;
	while (k > 0) {
		while (ptr < n && bits[ptr] == 1)
			ptr++;
		sptr = ptr+1;
		while (sptr < n && bits[sptr] == 1)
			sptr++;

		if (ptr < n && sptr == n) {
			uses[ptr]++;
			uses[n-1]++;
			bits[ptr] = 1;
			bits[n-1] = 0;
			uses[0] += k-2;
			break;
		} if (sptr == n || ptr == n) {
			uses[0] += k;
			break;
		}
		bits[ptr] = 1;
		bits[sptr] = 1;
		uses[ptr]++;
		uses[sptr]++;
		k-=2;
	}

	for (int i : bits)
		cout << i;
	cout << "\n";
	for (int i : uses)
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

