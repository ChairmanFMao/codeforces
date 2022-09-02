#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n;
	cin >> n;
	map<string,int> occurs;
	vector<vector<string> > words(3, vector<string>(n));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			cin >> words[i][j];
			occurs[words[i][j]]++;
		}
	}

	for (int i = 0; i < 3; i++) {
		int score = 0;
		for (int j = 0; j < n; j++)
			score += occurs[words[i][j]] == 1 ? 3 : occurs[words[i][j]] == 2 ? 1 : 0;
		cout << score << " ";
	}
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

