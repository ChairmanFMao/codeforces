#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Epicly passed pretests :)

// After n calls, q will be back to its original form
const int mxN = 1e4;
int out[mxN+1];
int n;

bool finished() {
    for (int i = 1; i <= n; i++)
        if (out[i] == 0)
            return 0;
    return 1;
}

// Need to iterate across the array as there might be separate loops in it

void solve() {
    cin >> n;
    memset(out, 0, sizeof out);

    for (int i = 1; i <= n; i++) {
        if (out[i])
            continue;
        int start, next = -1, prev;
        cout << "? " << i << endl;
        cout.flush();
        cin >> prev;
        start = prev;
        while (next != start) {
            cout << "? " << i << endl;
            cout.flush();
            cin >> next;
            out[prev] = next;
            prev = next;
        }
    }
    cout << "! ";
    for (int i = 1; i <= n; i++)
        cout << out[i] << (i != n ? " " : "");
    cout << "\n";
}

int main(void) {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}