#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n;
	string s;
	cin >> n >> s;
	int open = 0;
	for (char c : s)
		open += c == '(' ? 1 : -1;

	if (open) {
		cout << "-1\n";
		return;
	}

	int out = 0, count = 0, start = 0;
	stack<int> Stack;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			count++;
			Stack.push(1);
		} if (s[i] == ')') {
			count--;
			if (sz(Stack) && Stack.top() == 1)
				Stack.pop();
			else {
				if (!sz(Stack))
					start = i;
				Stack.push(0);
			}
		}

		if (count == 0 && sz(Stack)) {
			out += i - start+1;
			while (sz(Stack))
				Stack.pop();
		}
	}

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

