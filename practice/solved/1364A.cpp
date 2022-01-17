#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Spend a bit of time debugging as I forgot to put some brackets in the right place
// Failed first try, WA test 2, just a bug that was overlooked
// Failed second try, time limit test 3, due to using an O(n^2) algorithm
// Failed third try, time limit test 3, tried to make a better O(n^2) algorithm but, still too slow
// Failed fourth try, WA test 2, turns out new algorithm I made was bad
// Ended up looking at the solution as I was failing, solution was simpler than I thought
// Accepted on the fifth try!

void solve() {
    int n, x;
    cin >> n >> x;
    int numbers[n], all = 0;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        all += numbers[i];
    }
    
    if (all % x != 0) {
        cout << n << "\n";
        return;
    }
    int first = n+1, last = n+1;
    for (int i = 0; i < n; i++) {
        if (numbers[i] % x != 0) {
            first = i+1;
            break;
        }
    }
    for (int i = n-1; i >= 0; i--) {
        if (numbers[i] % x != 0) {
            last = n-i;
            break;
        }
    }
    cout << n - min(first,last) << "\n";
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