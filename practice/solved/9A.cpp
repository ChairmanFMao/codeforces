#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int y, w;
    cin >> y >> w;
    int score = 6 - max(y,w) + 1;
    int divisor = 6;
    for (int i = 2; i < 7; i++) {
        if (score % i == 0 && divisor % i == 0) {
            score /= i;
            divisor /= i;
            i--;
        }
    }
    cout << score << "/" << divisor << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}