
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Somehow getting a wrong answer on test 3 on test case 19k or smth, expected 3 but got 4
// Unsure where the error is.
// Had to look at solution, I made a silly mistake by not finding the rightmost offender.

const int mxN = 2e5;
vector<int> a(mxN);
int n;

int rightmost() {
    for (int i = n-1; i >= 0; i--)
        if (a[i] != a[n-1])
            return i;
    return n;
}

bool check() {
    int number = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] != number)
            return 0;
    return 1;
}

void copy(int pos) {
    for (int i = 0; i < n-pos; i++) {
        if (pos-i-1 >= 0 && pos+i < n)
            a[pos-i-1] = a[pos+i];
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // We need to call the function at the point with the longest streak behind it.
    // I think with this method I can achieve O(n log n)
    int moves = 0;
    while(!check()) {
        copy(rightmost()+1);
        moves++;
    }
    
    cout << moves << "\n";
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
