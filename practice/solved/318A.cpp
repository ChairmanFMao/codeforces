#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    long long nOverTwo = n%2 == 0 ? n/2 : n/2+1;
    if (k > nOverTwo) {
        cout << (k-nOverTwo)*2 << "\n";
    } else {
        cout << k*2-1 << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    solve();
}