#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed on first submission due to edge cases
// Second time was to overlooking some mechanic
// Third time was another edge case
// Accepted on fourth try.
// Need to try to think programs through a lot more for edge cases before submitting

void solve() {
    int m, s;
    cin >> m >> s;
    int copy = s, otherCopy = s;
    if (m == 1 && s == 0) {
        cout << 0 << " " << 0 << "\n";
        return;
    } if (s == 0 || m * 9 < s) {
        cout << -1 << " " << -1 << "\n";
        return;
    }
    string min = "1";
    otherCopy--;
    for (int i = 0; i < m-1; i++)
        min += '0';
    for (int i = m-1; i >= 0; i--) {
        if (otherCopy > 9) {
            min[i] = (char) (min[i] + 9);
            otherCopy -= 9;
        } else {
            min[i] = (char) (min[i] + otherCopy);
            break;
        }
    }
    string max = "";
    for (int i = 0; i < m; i++) {
        if (copy > 9) {
            max += to_string(9);
            copy -= 9;
        } else {
            max += to_string(copy);
            copy = 0;
        }
    }
    cout << min << " " << max << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    solve();
}