#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// All need to have exactly 2 neighbors in 8 region
// and at least one of them needs to be horizontal
// hack for old solution:
// 1
// 5 5
// .***.
// *...*
// *...*
// *...*
// .***.


const int mxN = 50;
int grid[50][50], seen[50][50];
int n, m;

bool invalid(int a, int b) {
	int out = 0, hori = 0;
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
			if (a+i >= 0 && a+i < n && b+j >= 0 && b+j < m) {
				out += grid[a+i][b+j];
				if (abs(i)+abs(j) == 1 && grid[a+i][b+j])
					hori = 1;
			}

	return out != 3 || !hori;
}

int expand(int a, int b, int s) {
	if (seen[a][b] || !grid[a][b])
		return 0;
	seen[a][b] = 1;
	s += grid[a][b];
	if (s > 3)
		return 1;
	int out = 0;
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
			if (a+i >= 0 && a+i < n && b+j >= 0 && b+j < m && !seen[a+i][b+j] && grid[a+i][b+j])
				out |= expand(a+i,b+j,s);

	return out;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			grid[i][j] = s[j] == '*';
			seen[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if ((grid[i][j] && invalid(i,j)) || expand(i,j,0)){
				cout << "NO\n";
				return;
			}

	cout << "YES\n";
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

