#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Coded the solution to deliberately avoid converting the number to a string, I think its more efficient this way, idk tho
// I did also have quite a lot of time to think about this problem
// Accepted first try!

ll calculate(ll number) {
    ll lowest = number%10, largest = number%10, copy = number;
    while (copy) {
        ll current = copy % 10;
        largest = max(largest,current);
        lowest = min(lowest,current);
        copy /= 10;
    }
    return number + lowest * largest;
}

bool noZero(ll number) {
    while (number) {
        if (number % 10 == 0)
            return false;
        number /= 10;
    }
    return true;
}

void solve() {
    ll a, k;
    cin >> a >> k;
    for (int i = 1; i < k && noZero(a); i++) {
        a = calculate(a);
    }
    cout << a << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}