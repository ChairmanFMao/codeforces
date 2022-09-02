#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// "Simple observation" cuts the queries down by a lot
// If there is a draw, neither player is the winner
// Can't rely on something being statistically good, edge cases
// Can't simulate the tournament - erase 3 participants in 2 q
// Its also built like the tree, its not random matching!
// Looked at tutorial but now it all makes sense
// The order of the matching is very important, but I didn't
// notice it


void solve() {
	int n;
	cin >> n;
	vector<int> current, next;
	for (int i = 1; i <= (1<<n); i++)
		current.push_back(i);

	while (sz(current) > 1) {
		next.clear();
		if (sz(current) == 2) {
			cout << "? " << current[0] << " " << current[1] << endl;
			int a;
			cin >> a;
			next.push_back(current[a==2]);
		} else {
			for (int i = 0; i < sz(current); i+=4) {
				cout << "? " << current[i] << " " << current[i+2] << endl;
				int a;
				cin >> a;
				if (a == 0) {
					cout << "? " << current[i+1] << " " << current[i+3] << endl;
					cin >> a;
					next.push_back(current[a==1?i+1:i+3]);
				} else if (a == 1) {
					cout << "? " << current[i] << " " << current[i+3] << endl;
					cin >> a;
					next.push_back(current[a==1?i:i+3]);
				} else if (a == 2) {
					cout << "? " << current[i+1] << " " << current[i+2] << endl;
					cin >> a;
					next.push_back(current[a==1?i+1:i+2]);
				}
			}
		}
		current = next;
	}
	
	cout << "! " << current[0] << endl;
}

int main(void) {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

