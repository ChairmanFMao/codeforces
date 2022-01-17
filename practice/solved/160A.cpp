#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> coins;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        coins.push_back(a);
        sum += a;
    }
    sort(coins.begin(), coins.end());
    int smallSum = 0, counter = 0;
    for (int i = n-1; smallSum <= sum/2; i--) {
        smallSum += coins[i];
        counter++;
    }
    cout << counter << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    solve();
}