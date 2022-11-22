#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Might be dp as |s| <= 2000
// its not just greedy I don't think
// if both ends are the same just pick one with
// worse after else do greedy
// Im not sure if the greedy has to work tho
// I think that this strategy can be done in O(n^2)
// This strategy gets wa on test 2
// I'm going to try to think of counterexamples
// before looking at the test cases I failed on
// I thought that you want to reverse it for
// when there is more than just a simple compare
// I think there might be more to it than that
// I didn't really read the question
// the letters are prepended to the string
// This means that the last choice is the most
// important for each player
// Unsure if it is ever possible for Bob to win
// I don't think it is because there is always
// an even number of characters and he gets the
// second pick, the best he can do is to draw
// just iterate over consecutive pairs and check
// to see if it would be possible for a draw
// looked at test cases, current counterexample:
// baabaa, should be Alice not draw
// There are actually only n^2 game states I think
// just try and see if making a move leads to a
// gameset with only wins or only draws
// transitional dp?
// build up from pairs all the way to the whole
// array and you can see if all the sub problems
// have 100% Alice or otherwise then it would
// be a draw
// If one of the children is 100% Alice then
// we can say that the current node is 100% Alice
// Each node will have 4 children of the moves
// possible, we can calculate all of the base cases for the dp and go upwards I think
// The dp transitions aren't working properly
// I got a lot of wa because I didn't think too much about the dp
// It is a cool problem and I liked it but, I shouldn't have
// looked at the test cases that I was failing on

void solve() {
	string s;
	cin >> s;
	int n = sz(s);

	// Draw will be represented as 1, Alice as 0
	map<pair<int,int>, int> m;
	// This is the difference between the start and the end
	for (int i = 1; i < n; i+=2) {
		for (int j = 0; j < n-i; j++) {
			// Does all the base cases
			if (i == 1) {
				m[{j,j+i}] = (s[j] == s[j+i]);
				continue;
			}

			m[{j,j+i}] = 0;
			int a = 0, b = 0, c = 0;
			// Alice and Bob do one on each side
			if (m[{j+1,j+i-1}] == 1 && s[j] == s[j+i])
				a = 1;
			// Alice and Bob move on right side
			if (m[{j,j+i-2}] == 1 && s[j+i] == s[j+i-1])
				b = 1;
			// Alice and Bob move on left side
			if (m[{j+2,j+i}] == 1 && s[j] == s[j+1])
				c = 1;
			m[{j,j+i}] = a|(b&c);
		}
	}

	//for (int i = 0; i < n; i++)
		//for (int j = 0; j < n; j++)
			//cout << m[{i,j}] << " \n"[j==n-1];

	cout << (m[{0,n-1}] ? "Draw" : "Alice") << "\n";
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

