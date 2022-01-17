#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Epicly first try!

void solve() {
    int n;
    cin >> n;
    vector<int> numbers;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        numbers.push_back(a);
    }
    sort(numbers.begin(), numbers.end());
    int grannies = 1;
    for (int i = n-1; i >= 0; i--) {
        if (i + grannies >= numbers[i]) {
            grannies += i + 1;
            break;
        }
    }
    cout << grannies << "\n";
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