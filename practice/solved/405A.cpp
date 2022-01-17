#include <bits/stdc++.h>
using namespace std;

// First of the 900 grind accepted first try!

void solve() {
    int n;
    cin >> n;
    vector<int> heights;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        heights.push_back(a);
    }
    sort(heights.begin(), heights.end());
    for (int i = 0; i < n; i++)
        cout << heights[i] << " ";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}