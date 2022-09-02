#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

const int mxN = 1e5;
vector<vector<int> > possible(mxN);
vector<int> squares;

void solve() {
	int n;
	cin >> n;
	vector<int> out(n,-1), used(n,0);
	for (int i = 0; i < n; i++)
		possible[i].clear();
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < sz(squares); j++)
			if (squares[j]-i < n && squares[j]-i >= 0)
				possible[i].push_back(squares[j]-i);

	for (int i = n-1; ~i; i--) {
		for (int j = sz(possible[i])-1; ~j; j--)
			if (!used[possible[i][j]]) {
				out[i] = possible[i][j];
				used[possible[i][j]] = 1;
				break;
			}
	}

	if (*min_element(all(out)) == -1) {
		cout << "-1\n";
		return;
	}

	for (int i : out)
		cout << i << " ";
	cout << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 450; i++)
		squares.push_back(i*i);
	
	cout << "\n";
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

