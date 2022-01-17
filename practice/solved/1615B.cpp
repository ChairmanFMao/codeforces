#include <bits/stdc++.h>
using namespace std;
#define ll long long

// I looked at the editorial and using their concept I managed to make this solution
// It utilises prefix sums for the totals which is what my original algorithm lacked
// in the actual contest as it timed out.

vector<vector<int>> prefix(32);
vector<int> running(32,0);

void solve() {
    int l, r;
    cin >> l >> r;

    int range = r-l+1, smallest = 1e9;
    for (int i = 0; i < 32; i++) {
        smallest = min(smallest, range - (prefix[i][r] - prefix[i][l-1]));
    }
    cout << smallest << "\n";
}

void genPrefix() {
    for (int i = 0; i < 32; i++)
        prefix[i].push_back(0);
    for (int i = 1; i <= (int)2e5; i++) {
        for (int j = 0; j < 32; j++) {
            if ((1 << j) & i)
                running[j]++;
            prefix[j].push_back(running[j]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    genPrefix();

    cout << "\n";
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve();
}