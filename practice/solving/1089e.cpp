#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// misread the question lol
// all visited cells are different
// I think the strat it to complete the top row
// then snake down
// Edge case where n = 9, we can do manually
// all others should conform to this model
// a1 is being repeated in this method, kinda forgot about that

void solve() {
	int n;
	cin >> n;

	vector<pair<int,int>> history = {{0,0}};
	if (n == 15) {
		// Adds 8
		for (int i = 1; i < 8; i++, n--)
			history.push_back({0,i});
		// Adds 3
		history.push_back({1,7});
		history.push_back({1,6});
		history.push_back({1,5});
		n -= 3;
		for (int i = 2; i < n; i++)
			history.push_back({i,5});
		history.push_back({7,5});
		history.push_back({7,7});
		for (pair<int,int> i : history)
			cout << (char)(i.f+97) << i.s+1 << " ";
		return;
	}
	
	int x = 0, y = 0;
	while (n > 0) {
		// End on top row
		if (n == 1 && y == 7) {
			history.push_back({7,7});
			break;
		}
		// End on last upwards
		if (n == 1 && x == 7) {
			history.push_back({7,7});
			break;
		}
		// End on any point
		if (n == 2 && y != 7 && x != 7) {
			history.push_back({7,y});
			history.push_back({7,7});
			break;
		}

		// Start upwards
		if (x == 0 && y < 7)
			y++;
		// end upwards
		else if (x == 7)
			y++;
		// across end
		else if (y == 0 && x == 1)
			x = 7;
		// right down
		else if ((y&1) && x == 6)
			y--;
		// right across
		else if (y&1)
			x++;
		// left down
		else if (!(y&1) && x == 1 && y != 0)
			y--;
		// left across
		else if (!(y&1))
			x--;
		history.push_back({x,y});
		n--;
	}

	for (pair<int,int> i : history)
		cout << (char)(i.f+97) << i.s+1 << " ";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

