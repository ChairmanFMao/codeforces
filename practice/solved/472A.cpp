#include <bits/stdc++.h>
using namespace std;

bool prime(int n) {
    if (n == 2) {
        return true;
    } if (n % 2 == 0)
        return false;
    for (int i = 3; i < n; i+=2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int n;
    cin >> n;
    for (int i = 2; i <= n/2; i++) {
        if (!prime(i) && !prime(n-i)) {
            cout << i << " " << n-i << "\n";
            return 0;
        }
    }
    return 1;
}