#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Accepted first try!

void solve() {
    int n;
    cin >> n;
    int people[n];
    for (int i = 0; i < n; i++)
        cin >> people[i];


    int twofive = 0, fifty = 0;
    for (int i = 0; i < n; i++) {
        int a = people[i];
        if (a == 25)
            twofive++;
        if (a == 50) {
            twofive--;
            fifty++;
        } if (a == 100) {
            if (twofive > 0 && fifty > 0) {
                twofive--;
                fifty--;
            } else
                twofive -= 3;
        }
        if (twofive < 0 || fifty < 0) {
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}