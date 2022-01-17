#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Accepted first try!
// Just a floating window sum kinda question

void solve() {
    int n;
    cin >> n;
    int numbers[n], sortedNumbers[n];
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        numbers[i] = a;
        sortedNumbers[i] = a;
    }
    sort(sortedNumbers, sortedNumbers+n);
    ll numbersSum[n+1], sortedSum[n+1], numbersCurrent = 0, sortedCurrent = 0;
    numbersSum[0] = 0;
    sortedSum[0] = 0;
    for (int i = 1; i <= n; i++) {
        numbersCurrent += numbers[i-1];
        sortedCurrent += sortedNumbers[i-1];
        numbersSum[i] = numbersCurrent;
        sortedSum[i] = sortedCurrent;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            cout << numbersSum[r] - numbersSum[l-1] << "\n";
        } else {
            cout << sortedSum[r] - sortedSum[l-1] << "\n";
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}