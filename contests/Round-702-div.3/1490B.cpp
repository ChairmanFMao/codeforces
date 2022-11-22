#include <bits/stdc++.h>
using namespace std;
#define ll long long

// First try as well :))))

void solve() {
    int n;
    cin >> n;
    int zero = 0, one = 0, two = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a % 3 == 0)
            zero++;
        else if (a % 3 == 1)
            one++;
        else if (a % 3 == 2)
            two++;
    }
    int moves = 0;
    while (zero != n/3 || one != n/3 || two != n/3) {
        if (zero > n/3) {
            one += zero - n/3;
            moves += zero - n/3;
            zero = n/3;
        } if (one > n/3) {
            two += one - n/3;
            moves += one - n/3;
            one = n/3;
        } if (two > n/3) {
            zero += two - n/3;
            moves += two - n/3;
            two = n/3;
        }
    }
    cout << moves << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}