#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed on first submission due to runtime error on test 2, forgot to account for if the queue became empty
// Failed on second, WA test 4, didn't use ll ;-;
// Accepted third try!

void solve() {
    int n, x;
    cin >> n >> x;
    ll all = 0, rich = 0, above = 0;
    priority_queue<int> notRich;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        all += a;
        if (a >= x)
            rich++;
        if (a > x)
            above += a - x;
        if (a < x)
            notRich.push(a);
    }

    if (above == 0) {
        cout << rich << "\n";
        return;
    }
    while (!notRich.empty()) {
        int next = notRich.top();
        notRich.pop();
        if (above >= x-next) {
            above -= x-next;
            rich++;
        } else
            break;
    }
    cout << rich << "\n";
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