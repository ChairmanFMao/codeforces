#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Iterate over the n diagonals and see which one has the biggest number of ones
// Takes this away from the total and that will be the number of xor

const int mxN = 2e3;
vector<vector<bool> > grid(mxN, vector<bool> (mxN));
int n;

int calc(int start) {
	int out = 0;
	for (int i = 0; i < n; i++)
		out += grid[i][(i+start)%n];
	
	return out;
}

void solve() {
	cin >> n;
	ll total = 0;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			grid[i][j] = stoi(s.substr(j,1));
			total += grid[i][j];
		}
	}
		
	int out = 0;
	for (int i = 0; i < n; i++)
		out = max(out, calc(i));

	cout << total - out + n-out << "\n";
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

