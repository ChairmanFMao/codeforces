#include <bits/stdc++.h>
using namespace std;

// Remember to use long long ideally if memory is not really a constraint as it may lead to failures in the test cases.

void solve() {
    int n;
    cin >> n;
    long long coins = 0, neg = 0, zero = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a < 0) {
            neg++;
            coins += abs(a + 1);
        } else if (a > 0) {
            coins += a - 1;
        } else {
            zero++;
            coins++;
        }
    }
    if (neg % 2 == 0 || (neg % 2 == 1 && zero > 0)) {
        cout << coins << "\n";
    } else {
        cout << coins+2 << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    solve();
}