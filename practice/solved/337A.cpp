#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> puzzles;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        puzzles.push_back(a);
    }
    sort(puzzles.begin(), puzzles.end());
    int smallest = 100000;
    for (int i = 0; i < m - n + 1; i++) {
        if (puzzles[i+n-1] - puzzles[i] < smallest)
            smallest = puzzles[i+n-1] - puzzles[i];
    }
    cout << smallest;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}