#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Accepted first try!
// I decided to just run a simulation of what was happening as a1 <= 100 and a2 <= 100 so it would be efficient enough

void solve() {
    int a1, a2;
    cin >> a1 >> a2;

    int mins = 0;
    while (a1 > 0 && a2 > 0) {
        if (a1 == 1 && a2 == 1)
            break;
        else if (a1 >= a2) {
            a1-=2;
            a2++;
        } else if (a2 > a1) {
            a2-=2;
            a1++;
        }
        mins++;
    }
    cout << mins << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}