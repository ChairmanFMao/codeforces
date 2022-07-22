#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// I think that this might be able to be done with dp
// I think if u store pairs you could trace back the solution
// Just store the previous +1 so it will evaluate to true
// I also did this without editorial, some very nice dp

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	vector<vector<int> > dp(n,vector<int>(5,0));
	for (int i = 0; i < 5; i++)
		dp[0][i] = i+1;
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				if (a[i] < a[i+1] && j < k && dp[i][j])
					dp[i+1][k] = j+1;
				else if (a[i] > a[i+1] && j > k && dp[i][j])
					dp[i+1][k] = j+1;
				else if (a[i] == a[i+1] && j != k && dp[i][j])
					dp[i+1][k] = j+1;
			}
		}
	}

	int trace = -1;
	for (int i = 0; i < 5; i++)
		if (dp[n-1][i])
			trace = i;

	if (trace == -1) {
		cout << "-1\n";
		return;
	}

	int current = n-1;
	stack<int> out;
	while (current >= 0) {
		out.push(trace);
		trace = dp[current][trace-1];
		current--;
	}

	while (sz(out)) {
		cout << out.top() << " ";
		out.pop();
	}
	cout << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

