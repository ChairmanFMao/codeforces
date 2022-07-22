#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// working from right to left
// parenthesis only effect the order of operations
// I think there might be a recursive way to do this
// I think that I might be recalculating areas currently
// I looked at tutorial but had to edit the idea a bit
string s;

pair<int,int> recur(int start) {
	int out = 0, ptr = start, current = 0;
	while (1) {
		while (s[ptr] != '(')
			ptr++;
		ptr++;
		if (s[ptr] == ')') {
			current = 0;
			ptr++;
		} else {
			pair<int,int> a = recur(ptr);
			current = a.first;
			ptr = a.second+1;
		}
		if (s[ptr] == ')' || ptr >= sz(s)) {
			out = max(out,current);
			break;
		}
		
		while (s[ptr] == '-')
			ptr++;
		while (s[ptr] == '>')
			ptr++;

		out = max(out, current+1);
	}
	return {out,ptr};
}

void solve() {
	cin >> s;
	cout << recur(0).first;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

