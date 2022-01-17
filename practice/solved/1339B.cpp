#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Accepted first try!

void solve() {
    int n;
    cin >> n;
    int numbers[n];
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    
    sort(numbers, numbers+n);
    int out[n], ePtr = n-1, sPtr = 0, oPtr = n-1;
    while (oPtr >= 0) {
        out[oPtr] = numbers[sPtr];
        sPtr++;
        oPtr--;
        if (oPtr < 0)
            break;
        out[oPtr] = numbers[ePtr];
        ePtr--;
        oPtr--;
    }
    for (int i = 0; i < n; i++) {
        cout << out[i] << " ";
    }
    cout << "\n";
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