#include <bits/stdc++.h>
using namespace std;

// Accepted first try, lets go!

void solve() {
    long long  n;
    cin >> n;
    long long minutes = 0;
    if (n <= 6) {
        cout << 15 << "\n";
        return;
    }
    if (n & 1 == 1)
        n++;
    // We keep taking away 6 for small pizzas until n is divisible by 10 and we can just to the rest large
    // Due to each pizza's slice to time ratio being the same we can do this and it will still be the most efficient way to cook the pizzas
    while (n % 10 != 0) {
        minutes += 15;
        n -= 6;
    }
    minutes += n / 10 * 25;
    cout << minutes << "\n";
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