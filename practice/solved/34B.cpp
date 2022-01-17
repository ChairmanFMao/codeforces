#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> prices;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        prices.push_back(a);
    }
    sort(prices.begin(), prices.end());
    int profit = 0;
    for (int i = 0; prices[i] < 0 && i < m; i++)
        profit -= prices[i];
    cout << profit;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    solve();
}