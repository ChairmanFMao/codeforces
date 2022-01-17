#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> numbers;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
        numbers.push_back(a);
    }
    if (sum % n != 0) {
        cout << -1 << "\n";
        return;
    }
    int average = sum / n, more = 0;
    for (int i = 0; i < n; i++) {
        if (numbers[i] > average)
            more++;
    }
    cout << more << "\n";
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