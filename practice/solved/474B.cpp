#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first try, WA test 2, left an equal sign at ln 26, col 57 that screwed up one test case
// Accepted second try!

void solve() {
    int n;
    cin >> n;
    int sums[n], worms[n], all = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        all += a;
        sums[i] = all;
        worms[i] = a;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        int upper = n-1, lower = 0;
        while (lower <= upper) {
            int mid = (upper + lower)/2;
            if (sums[mid] >= a && sums[mid]-worms[mid] < a) {
                cout << mid+1 << "\n";
                break;
            }
            else if (sums[mid] < a)
                lower = mid+1;
            else if (sums[mid] > a)
                upper = mid;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}