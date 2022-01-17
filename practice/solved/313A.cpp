#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    if (n >= 0) {
        cout << n;
        return;
    }
    int last = n*-1 % 10;
    int secondLast = (n*-1 / 10) % 10;
    if (last >= secondLast) {
        cout << n/10;
    } else {
        cout << (n/100)*10 - last;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}