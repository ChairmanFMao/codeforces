#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int toasts = min(min(k * l / nl, c * d), p / np);
    cout << toasts/n;
}