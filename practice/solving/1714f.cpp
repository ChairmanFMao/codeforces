#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Lets goooooo!!!!!!! :)
// I got this to pass first try!

// So the plan is to set d1 and d2 their set distance apart
// Then iterate through that and see how far out d3 needs to be
// If it is valid at one of those positions we output that
// excess nodes can be attached on the end of d1 or d2
// Might be easier to store as a vector initially then convert
// to a graph later
//
// We need abritary nodes from 1 to 2
// d3 may actually be along this path
// Then if d3 is off the path we add more abritary
// then we dump all extra nodes hanging off 1

void solve() {
	int n, d12, d23, d31;
	cin >> n >> d12 >> d23 >> d31;

	// We set nodes 1 and 2, d12 apart
	int used = d12;

	// Iterating from d1 to d2 along the line
	for (int i = 0; i <= used; i++) {
		// calculates the extention required
		int extend = d31 - i;
		// Need to remove extend from used if extend == 0
		if (extend < 0 || extend > n-used + (extend?-1:0))
			continue;

		// Checks for if the graph is good
		if (d23 == extend + d12-i) {
			cout << "YES\n";
			
			// This is the base array
			vector<int> out(used+1);
			int ptr = 4;
			for (int j = 0; j <= used; j++) {
				if (j == 0 || j == used)
					out[j] = j == 0 ? 1 : 2;
				else if (j == i && !extend)
					out[j] = 3;
				else
					out[j] = ptr++;
			}

			// This is the extension for 3
			vector<int> three = {out[i]};
			if (extend) {
				for (int j = 0; j < extend-1; j++)
					three.push_back(ptr++);

				three.push_back(3);
			}

			// These are the excess nodes
			vector<int> extra = {1};
			while (ptr <= n)
				extra.push_back(ptr++);

			for (int j = 0; j < sz(out)-1; j++)
				cout << out[j] << " " << out[j+1] << "\n";

			for (int j = 0; j < sz(three)-1; j++)
				cout << three[j] << " " << three[j+1] << "\n";

			for (int j = 0; j < sz(extra)-1; j++)
				cout << extra[j] << " " << extra[j+1] << "\n";

			return;
		}
	}

	cout << "NO\n";
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

