#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// I think it would be easiest to get them both to be zero
// epicly gets wa on test 2
// Just need to solve this problem now
// groups of 4 xor to zero
// just need to solve for 3 - 7 manually
// still wa on test case 2 somehow

void solve() {
	int n;
	cin >> n;
	if (n % 8 == 1)
		cout << "0 ";
	if (n % 8 == 2)
		cout << "4 0 ";
	if (n % 8 == 3)
		cout << "1 2 3 ";
	if (n % 8 == 4)
		cout << "0 1 2 3 ";
	if (n % 8 == 5)
		cout << "2 0 3 5 4 ";
	if (n % 8 == 6)
		cout << "4 1 2 12 3 8 ";
	if (n % 8 == 7)
		cout << "1 2 3 4 5 6 7 ";

	int m = n/8;
	vector<int> even, odd;
	int start = 16;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < 4; j++) {
			even.push_back(start);
			start++;
		}

	for (int i = 0; i < m; i++) {
		if (i == m-1 && (start & 4) == 4)
			start += 8;
		for (int j = 0; j < 4; j++) {
			odd.push_back(start);
			start++;
		}
	}
	
	if (n % 8 == 2 && sz(odd))
		odd[sz(odd)-1] ^= 4;

	for (int i = 0; i < sz(even); i++)
		cout << even[i] << " " << odd[i] << " ";
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

