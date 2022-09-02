#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Getting 48 instead of 45 for one of the test cases
// Mabye its a dp problem? The greedy doesn't work well
// dp would work well but tracing the operations back would
// be a little bit difficult
// I think dp wouldn't be that bad, each state stores score and previous
// always choose the state with the lowest score
// Very happy that this dp worked! :)

struct State {
	int last, pos, score;
};

void solve() {
	string t;
	int n;
	cin >> t >> n;
	vector<string> s(n);
	for (string& i : s)
		cin >> i;

	vector<State> dp(sz(t)+1);
	for (State& i : dp) {
		i.score = 1e9;
		i.last = -1;
		i.pos = -1;
	}

	State state;
	state.last = -1; state.pos = -1; state.score = 0;
	dp[0] = state;
	for (int i = 0; i < sz(t); i++) {
		for (int j = 0; j < n; j++) {
			if (t.substr(i,sz(s[j])) == s[j]) {
				for (int k = i+1; k < i+sz(s[j])+1; k++) {
					if (dp[i].score + 1 < dp[k].score) {
						state.last = j; state.pos = i; state.score = dp[i].score + 1;
						dp[k] = state;
					}
				}
			}
		}
	}

	if (dp[sz(t)].score == 1e9) {
		cout << "-1\n";
		return;
	}

	cout << dp[sz(t)].score << "\n";
	int ptr = sz(t);
	while (ptr) {
		cout << dp[ptr].last+1 << " " << dp[ptr].pos+1 << "\n";
		ptr = dp[ptr].pos;
	}
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

